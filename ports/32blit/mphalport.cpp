#include <unistd.h>

#include "py/mpconfig.h"

#include "engine/api_private.hpp"

// Receive single character, blocking until one is available.
extern "C" int mp_hal_stdin_rx_chr(void) {
    unsigned char c = 0;
#ifdef TARGET_32BLIT_HW
    // TODO
#else
    int r = read(STDIN_FILENO, &c, 1);
    (void)r;
#endif
    return c;
}

// Send the string of given length.
extern "C" void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {

#ifdef TARGET_32BLIT_HW
    blit::api.write_cdc((uint8_t *)str, len);
#else
    int r = write(STDOUT_FILENO, str, len);
    (void)r;
#endif
}
