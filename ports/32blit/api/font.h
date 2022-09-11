#pragma once

#include "../mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_Font_char_w(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Font_char_h(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Font_spacing_y(size_t n_args, const mp_obj_t *args);

extern const mp_obj_type_t blit_Font_type;

#ifdef __cplusplus
}
#endif
