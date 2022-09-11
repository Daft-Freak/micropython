#pragma once

#include "../mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_Point_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
mp_obj_t blit_Point_x(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Point_y(size_t n_args, const mp_obj_t *args);

extern const mp_obj_type_t blit_Point_type;

#ifdef __cplusplus
}
#endif
