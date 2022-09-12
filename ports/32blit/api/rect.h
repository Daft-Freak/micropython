#pragma once

#include "../mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_Rect_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
mp_obj_t blit_Rect_size(mp_obj_t self);
mp_obj_t blit_Rect_empty(mp_obj_t self);
mp_obj_t blit_Rect_contains(mp_obj_t self, mp_obj_t pos_rect_obj);
mp_obj_t blit_Rect_intersects(mp_obj_t self, mp_obj_t r_obj);
mp_obj_t blit_Rect_intersection(mp_obj_t self, mp_obj_t r_obj);
mp_obj_t blit_Rect_deflate(mp_obj_t self, mp_obj_t v_obj);
mp_obj_t blit_Rect_inflate(mp_obj_t self, mp_obj_t v_obj);
mp_obj_t blit_Rect_clamp(mp_obj_t self, mp_obj_t p_obj);
mp_obj_t blit_Rect_tl(mp_obj_t self);
mp_obj_t blit_Rect_tr(mp_obj_t self);
mp_obj_t blit_Rect_bl(mp_obj_t self);
mp_obj_t blit_Rect_br(mp_obj_t self);
mp_obj_t blit_Rect_center(mp_obj_t self);
mp_obj_t blit_Rect_binary_op(mp_binary_op_t op, mp_obj_t lhs, mp_obj_t rhs);
mp_obj_t blit_Rect_x(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Rect_y(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Rect_w(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Rect_h(size_t n_args, const mp_obj_t *args);

extern const mp_obj_type_t blit_Rect_type;

#ifdef __cplusplus
}
#endif
