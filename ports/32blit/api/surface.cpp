#include "surface.h"

#include "../blit-helpers.hpp"

using namespace blit;

mp_obj_t blit_Surface_clear(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj(self, Surface);

    this_ptr->clear();
    return mp_const_none;
}

mp_obj_t blit_Surface_pixel(mp_obj_t self, mp_obj_t p_obj) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    Point p = blit_obj_to_Point(p_obj);

    this_ptr->pixel(p);
    return mp_const_none;
}

mp_obj_t blit_Surface_v_span(mp_obj_t self, mp_obj_t p_obj, mp_obj_t c_obj) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    Point p = blit_obj_to_Point(p_obj);
    int16_t c = mp_obj_get_int(c_obj);

    this_ptr->v_span(p, c);
    return mp_const_none;
}

mp_obj_t blit_Surface_h_span(mp_obj_t self, mp_obj_t p_obj, mp_obj_t c_obj) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    Point p = blit_obj_to_Point(p_obj);
    int16_t c = mp_obj_get_int(c_obj);

    this_ptr->h_span(p, c);
    return mp_const_none;
}

mp_obj_t blit_Surface_rectangle(mp_obj_t self, mp_obj_t r_obj) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    Rect r = blit_obj_to_Rect(r_obj);

    this_ptr->rectangle(r);
    return mp_const_none;
}

mp_obj_t blit_Surface_circle(mp_obj_t self, mp_obj_t c_obj, mp_obj_t r_obj) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    Point c = blit_obj_to_Point(c_obj);
    int32_t r = mp_obj_get_int(r_obj);

    this_ptr->circle(c, r);
    return mp_const_none;
}

mp_obj_t blit_Surface_line(mp_obj_t self, mp_obj_t p1_obj, mp_obj_t p2_obj) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    Point p1 = blit_obj_to_Point(p1_obj);
    Point p2 = blit_obj_to_Point(p2_obj);

    this_ptr->line(p1, p2);
    return mp_const_none;
}

mp_obj_t blit_Surface_triangle(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);
    Point p1 = blit_obj_to_Point(args[1]);
    Point p2 = blit_obj_to_Point(args[2]);
    Point p3 = blit_obj_to_Point(args[3]);

    this_ptr->triangle(p1, p2, p3);
    return mp_const_none;
}

mp_obj_t blit_Surface_blit(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);
    Surface *src = blit_unwrap_obj(args[1], Surface);
    Rect src_r = blit_obj_to_Rect(args[2]);
    Point dst_p = blit_obj_to_Point(args[3]);
    int transforms = mp_obj_get_int(args[4]);

    this_ptr->blit(src, src_r, dst_p, transforms);
    return mp_const_none;
}

mp_obj_t blit_Surface_stretch_blit(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);
    Surface *src = blit_unwrap_obj(args[1], Surface);
    Rect src_r = blit_obj_to_Rect(args[2]);
    Rect dst_r = blit_obj_to_Rect(args[3]);
    int transforms = mp_obj_get_int(args[4]);

    this_ptr->stretch_blit(src, src_r, dst_r, transforms);
    return mp_const_none;
}

mp_obj_t blit_Surface_stretch_blit_vspan(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);
    Surface *src = blit_unwrap_obj(args[1], Surface);
    Point uv = blit_obj_to_Point(args[2]);
    uint16_t sc = mp_obj_get_int(args[3]);
    Point p = blit_obj_to_Point(args[4]);
    int16_t dc = mp_obj_get_int(args[5]);

    this_ptr->stretch_blit_vspan(src, uv, sc, p, dc);
    return mp_const_none;
}

mp_obj_t blit_Surface_watermark(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj(self, Surface);

    this_ptr->watermark();
    return mp_const_none;
}

mp_obj_t blit_Surface_bounds(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        Size bounds = blit_obj_to_Size(args[1]);

        this_ptr->bounds = bounds;
    }

    return blit_obj_from_Size(this_ptr->bounds);
}

mp_obj_t blit_Surface_clip(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        Rect clip = blit_obj_to_Rect(args[1]);

        this_ptr->clip = clip;
    }

    return blit_obj_from_Rect(this_ptr->clip);
}

mp_obj_t blit_Surface_alpha(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        uint8_t alpha = mp_obj_get_int(args[1]);

        this_ptr->alpha = alpha;
    }

    return mp_obj_new_int(this_ptr->alpha);
}

mp_obj_t blit_Surface_pen(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        Pen pen = blit_obj_to_Pen(args[1]);

        this_ptr->pen = pen;
    }

    return blit_obj_from_Pen(this_ptr->pen);
}

mp_obj_t blit_Surface_mask(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        Surface *mask = blit_unwrap_obj(args[1], Surface);

        this_ptr->mask = mask;
    }

    return blit_wrap_obj(this_ptr->mask, Surface);
}

mp_obj_t blit_Surface_sprites(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        Surface *sprites = blit_unwrap_obj(args[1], Surface);

        this_ptr->sprites = sprites;
    }

    return blit_wrap_obj(this_ptr->sprites, Surface);
}

mp_obj_t blit_Surface_transparent_index(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        uint8_t transparent_index = mp_obj_get_int(args[1]);

        this_ptr->transparent_index = transparent_index;
    }

    return mp_obj_new_int(this_ptr->transparent_index);
}

mp_obj_t blit_Surface_rows(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        uint16_t rows = mp_obj_get_int(args[1]);

        this_ptr->rows = rows;
    }

    return mp_obj_new_int(this_ptr->rows);
}

mp_obj_t blit_Surface_cols(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Surface);

    if(n_args > 1) {
        uint16_t cols = mp_obj_get_int(args[1]);

        this_ptr->cols = cols;
    }

    return mp_obj_new_int(this_ptr->cols);
}
