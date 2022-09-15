#include <cstdlib>
#include <unistd.h>

extern "C" {
#include "py/builtin.h"
#include "py/compile.h"
#include "py/gc.h"
#include "py/mperrno.h"
#include "py/mphal.h"
#include "py/stackctrl.h"
#include "extmod/vfs.h"
#include "shared/runtime/gchelper.h"
#include "shared/runtime/pyexec.h"
}

#include "32blit.hpp"
#include "engine/api_private.hpp"

#include "vfs-blit.h"

// Allocate memory for the MicroPython GC heap.
static char heap[128 * 1024];

static bool repl_enabled = true;

static void do_mp_init() {
    mp_init();

    MP_STATE_PORT(render_callback_obj) = nullptr;
    MP_STATE_PORT(update_callback_obj) = nullptr;

    // mount fs
    mp_obj_t args[2] = {
        blit_vfs_type.make_new(&blit_vfs_type, 0, 0, nullptr),
        MP_OBJ_NEW_QSTR(MP_QSTR__slash_),
    };
    mp_vfs_mount(2, args, (mp_map_t *)&mp_const_empty_map);
    MP_STATE_VM(vfs_cur) = MP_STATE_VM(vfs_mount_table);

    pyexec_event_repl_init();
}

static void reset() {
    gc_sweep_all();
    mp_deinit();

    do_mp_init();
    pyexec_event_repl_init();

#ifdef TARGET_32BLIT_HW
    if(!repl_enabled)
        blit::api.set_raw_cdc_enabled(true);
#endif
}

void init() {
    // Initialise the MicroPython runtime.
    mp_stack_ctrl_init();

#ifdef TARGET_32BLIT_HW
    extern char _edata, _estack;
    mp_stack_set_top(&_estack);
    mp_stack_set_limit(&_estack - &_edata - 256);
#endif

    gc_init(heap, heap + sizeof(heap));

    do_mp_init();

    // attempt to launch script
    auto launch_path = blit::get_launch_path();
    if(launch_path) {
        pyexec_file_if_exists(launch_path);

        if(MP_STATE_PORT(update_callback_obj) && MP_STATE_PORT(render_callback_obj))
            repl_enabled = false;
    }

    // fallback to repl
    if(repl_enabled) {
        pyexec_event_repl_init();

#ifdef TARGET_32BLIT_HW
        blit::api.set_raw_cdc_enabled(true);
#endif
    }
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

    if(!repl_enabled)
        return;

#ifdef TARGET_32BLIT_HW
    uint8_t b;
    while(blit::api.cdc_read(&b, 1)) {
        if (pyexec_event_repl_process_char(b)) {
            reset();
        }
    }

#else
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

