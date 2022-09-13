#pragma once

#include "../mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_Vec2_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
mp_obj_t blit_Vec2_normalize(mp_obj_t self);
mp_obj_t blit_Vec2_length(mp_obj_t self);
mp_obj_t blit_Vec2_cross(mp_obj_t self, mp_obj_t a_obj);
mp_obj_t blit_Vec2_dot(mp_obj_t self, mp_obj_t a_obj);
mp_obj_t blit_Vec2_rotate(mp_obj_t self, mp_obj_t a_obj);
mp_obj_t blit_Vec2_angle(mp_obj_t self, mp_obj_t o_obj);
mp_obj_t blit_Vec2_binary_op(mp_binary_op_t op, mp_obj_t lhs, mp_obj_t rhs);
mp_obj_t blit_Vec2_x(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Vec2_y(size_t n_args, const mp_obj_t *args);

extern const mp_obj_type_t blit_Vec2_type;

#ifdef __cplusplus
}
#endif
