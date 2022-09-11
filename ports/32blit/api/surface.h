#pragma once

#include "../mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_Surface_load(mp_obj_t filename_obj);
mp_obj_t blit_Surface_save(mp_obj_t self, mp_obj_t filename_obj);
mp_obj_t blit_Surface_clear(mp_obj_t self);
mp_obj_t blit_Surface_pixel(mp_obj_t self, mp_obj_t p_obj);
mp_obj_t blit_Surface_v_span(mp_obj_t self, mp_obj_t p_obj, mp_obj_t c_obj);
mp_obj_t blit_Surface_h_span(mp_obj_t self, mp_obj_t p_obj, mp_obj_t c_obj);
mp_obj_t blit_Surface_rectangle(mp_obj_t self, mp_obj_t r_obj);
mp_obj_t blit_Surface_circle(mp_obj_t self, mp_obj_t c_obj, mp_obj_t r_obj);
mp_obj_t blit_Surface_line(mp_obj_t self, mp_obj_t p1_obj, mp_obj_t p2_obj);
mp_obj_t blit_Surface_triangle(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_text(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
mp_obj_t blit_Surface_measure_text(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
mp_obj_t blit_Surface_wrap_text(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
mp_obj_t blit_Surface_blit(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
mp_obj_t blit_Surface_stretch_blit(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
mp_obj_t blit_Surface_stretch_blit_vspan(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_watermark(mp_obj_t self);
mp_obj_t blit_Surface_sprite_bounds(mp_obj_t self, mp_obj_t sprite_obj);
mp_obj_t blit_Surface_sprite(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
mp_obj_t blit_Surface_bounds(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_clip(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_alpha(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_pen(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_mask(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_sprites(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_transparent_index(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_rows(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_Surface_cols(size_t n_args, const mp_obj_t *args);

extern const mp_obj_type_t blit_Surface_type;

#ifdef __cplusplus
}
#endif
