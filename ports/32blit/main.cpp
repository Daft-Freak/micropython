#include <cstdlib>
#include <unistd.h>

extern "C" {
#include "py/builtin.h"
#include "py/compile.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "py/mphal.h"
#include "py/stackctrl.h"
#include "shared/runtime/gchelper.h"
#include "shared/runtime/pyexec.h"
}

#include "32blit.hpp"
#include "engine/api_private.hpp"

// Allocate memory for the MicroPython GC heap.
static char heap[128 * 1024];

#ifdef TARGET_32BLIT_HW
extern "C" void do_init(int);

// callback from CDC code
static void on_recv(const uint8_t *data, uint16_t len) {
    for(auto i = 0u; i < len; i++) {
        if (pyexec_event_repl_process_char(char(data[i]))) {

            // super hacky restart
            extern char flash_start;
            do_init((intptr_t)&flash_start & 0x1FFFFFF);
        }
    }
}

#endif

void init() {
    // Initialise the MicroPython runtime.
    mp_stack_ctrl_init();

#ifdef TARGET_32BLIT_HW
    extern char _edata, _estack;
    mp_stack_set_top(&_estack);
    mp_stack_set_limit(&_estack - &_edata - 256);
#endif

    gc_init(heap, heap + sizeof(heap));
    mp_init();

    MP_STATE_PORT(render_callback_obj) = nullptr;
    MP_STATE_PORT(update_callback_obj) = nullptr;

    pyexec_event_repl_init();

#ifdef TARGET_32BLIT_HW
    blit::api.cdc_received = on_recv;
#endif
}

void update(uint32_t time) {

    if(MP_STATE_PORT(update_callback_obj)) {
        nlr_buf_t nlr;

        if (nlr_push(&nlr) == 0) {
            mp_call_function_1(MP_STATE_PORT(update_callback_obj), mp_obj_new_int(time));
            nlr_pop();
        } else {
            // error
            mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);

            MP_STATE_PORT(update_callback_obj) = nullptr;
        }
    }

#ifndef TARGET_32BLIT_HW
    // messy stdin polling
    // TODO: don't do this
    struct timeval tv = {};

    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    while(true) {
        select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);

        if(FD_ISSET(0, &fds)) {
            int c = mp_hal_stdin_rx_chr();
            if (pyexec_event_repl_process_char(c)) {
                exit(0);
            }
        }
        else
            break;
    }
#endif
}

void render(uint32_t time) {
    if(MP_STATE_PORT(render_callback_obj)) {
        nlr_buf_t nlr;

        if (nlr_push(&nlr) == 0) {
            mp_call_function_1(MP_STATE_PORT(render_callback_obj), mp_obj_new_int(time));
            nlr_pop();
        } else {
            // error
            mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);

            MP_STATE_PORT(render_callback_obj) = nullptr;
        }
    }
}

// Handle uncaught exceptions (should never be reached in a correct C implementation).
void nlr_jump_fail(void *val) {
    for (;;) {
    }
}

// Do a garbage collection cycle.
void gc_collect(void) {
    gc_collect_start();
    gc_helper_collect_regs_and_stack();
    gc_collect_end();
}

