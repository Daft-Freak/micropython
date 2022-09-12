#pragma once

#include "../mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_Size_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
mp_obj_t blit_Size_empty(mp_obj_t self);
mp_obj_t blit_Size_area(mp_obj_t self);
mp_obj_t blit_Size_contains(mp_obj_t self, mp_obj_t p_obj);
mp_obj_t blit_Size_binary_op(mp_binary_op_t op, mp_obj_t lhs, mp_obj_t rhs);
mp_obj_t blit_Size_w(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Size_h(size_t n_args, const mp_obj_t *args);

extern const mp_obj_type_t blit_Size_type;

#ifdef __cplusplus
}
#endif
