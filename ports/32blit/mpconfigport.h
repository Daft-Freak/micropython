#include <stdint.h>

#ifndef MICROPY_CONFIG_ROM_LEVEL
#define MICROPY_CONFIG_ROM_LEVEL                (MICROPY_CONFIG_ROM_LEVEL_EXTRA_FEATURES)
#endif

// Python internal features.
#define MICROPY_ENABLE_GC                       (1)
#define MICROPY_READER_VFS                      (1)
#define MICROPY_HELPER_REPL                     (1)
#define MICROPY_ERROR_REPORTING                 (MICROPY_ERROR_REPORTING_TERSE)
#define MICROPY_FLOAT_IMPL                      (MICROPY_FLOAT_IMPL_FLOAT)

#define MICROPY_REPL_EVENT_DRIVEN               (1)

// Enable u-modules to be imported with their standard name, like sys.
#define MICROPY_MODULE_WEAK_LINKS               (1)

// Fine control over Python builtins, classes, modules, etc.
#define MICROPY_PY_ASYNC_AWAIT                  (0)
#define MICROPY_PY_IO                           (0)

#define MICROPY_PY_SYS_STDFILES                 (0)
#define MICROPY_PY_UASYNCIO                     (0)
#define MICROPY_PY_UJSON                        (0)
#define MICROPY_PY_USELECT                      (0)

#define MICROPY_VFS                             (1)

// Type definitions for the specific machine.

typedef intptr_t mp_int_t; // must be pointer size
typedef uintptr_t mp_uint_t; // must be pointer size
typedef long mp_off_t;

// We need to provide a declaration/definition of alloca().
#include <alloca.h>

// Define the port's name and hardware.
#define MICROPY_HW_BOARD_NAME "32blit"
#define MICROPY_HW_MCU_NAME   "unknown-cpu"

#define MP_STATE_PORT MP_STATE_VM

#define MICROPY_PORT_ROOT_POINTERS \
    const char *readline_hist[8]; \
    mp_obj_t render_callback_obj; \
    mp_obj_t update_callback_obj;
