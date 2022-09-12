#include "rect.h"

#include "../blit-helpers.hpp"

using namespace blit;

mp_obj_t blit_Rect_size(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    auto ret = this_ptr->size();
    return blit_obj_from_Size(ret);
}

mp_obj_t blit_Rect_empty(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    auto ret = this_ptr->empty();
    return mp_obj_new_bool(ret);
}

mp_obj_t blit_Rect_contains(mp_obj_t self, mp_obj_t pos_rect_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    if(blit_obj_is_Point(pos_rect_obj)) {
        Point pos_rect = blit_obj_to_Point(pos_rect_obj);
        auto ret = this_ptr->contains(pos_rect);
        return mp_obj_new_bool(ret);
    }

    if(blit_obj_is_Rect(pos_rect_obj)) {
        Rect pos_rect = blit_obj_to_Rect(pos_rect_obj);
        auto ret = this_ptr->contains(pos_rect);
        return mp_obj_new_bool(ret);
    }

    mp_raise_TypeError("invalid type for pos_rect");
    return mp_const_none;
}

mp_obj_t blit_Rect_intersects(mp_obj_t self, mp_obj_t r_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);
    Rect r = blit_obj_to_Rect(r_obj);

    auto ret = this_ptr->intersects(r);
    return mp_obj_new_bool(ret);
}

mp_obj_t blit_Rect_intersection(mp_obj_t self, mp_obj_t r_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);
    Rect r = blit_obj_to_Rect(r_obj);

    auto ret = this_ptr->intersection(r);
    return blit_obj_from_Rect(ret);
}

mp_obj_t blit_Rect_deflate(mp_obj_t self, mp_obj_t v_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);
    int32_t v = mp_obj_get_int(v_obj);

    this_ptr->deflate(v);
    return mp_const_none;
}

mp_obj_t blit_Rect_inflate(mp_obj_t self, mp_obj_t v_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);
    int32_t v = mp_obj_get_int(v_obj);

    this_ptr->inflate(v);
    return mp_const_none;
}

mp_obj_t blit_Rect_clamp(mp_obj_t self, mp_obj_t p_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);
    Point p = blit_obj_to_Point(p_obj);

    auto ret = this_ptr->clamp(p);
    return blit_obj_from_Point(ret);
}

mp_obj_t blit_Rect_tl(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    auto ret = this_ptr->tl();
    return blit_obj_from_Point(ret);
}

mp_obj_t blit_Rect_tr(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    auto ret = this_ptr->tr();
    return blit_obj_from_Point(ret);
}

mp_obj_t blit_Rect_bl(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    auto ret = this_ptr->bl();
    return blit_obj_from_Point(ret);
}

mp_obj_t blit_Rect_br(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    auto ret = this_ptr->br();
    return blit_obj_from_Point(ret);
}

mp_obj_t blit_Rect_center(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Rect);

    auto ret = this_ptr->center();
    return blit_obj_from_Point(ret);
}

mp_obj_t blit_Rect_binary_op(mp_binary_op_t op, mp_obj_t lhs, mp_obj_t rhs) {
    auto left_side = blit_unwrap_obj_val(lhs, Rect);
    switch (op) {
        case MP_BINARY_OP_MULTIPLY:
        case MP_BINARY_OP_INPLACE_MULTIPLY:
        {
            float right_side = mp_obj_get_float(rhs);
            return blit_obj_from_Rect(*left_side * right_side);
        }
        case MP_BINARY_OP_EQUAL:
        {
            auto right_side = blit_unwrap_obj_val(rhs, Rect);
            return mp_obj_new_bool(*left_side == *right_side);
        }
        case MP_BINARY_OP_NOT_EQUAL:
        {
            auto right_side = blit_unwrap_obj_val(rhs, Rect);
            return mp_obj_new_bool(*left_side != *right_side);
        }

        default:
            return MP_OBJ_NULL;
    }
}

mp_obj_t blit_Rect_x(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Rect);

    if(n_args > 1) {
        int32_t x = mp_obj_get_int(args[1]);

        this_ptr->x = x;
    }

    return mp_obj_new_int(this_ptr->x);
}

mp_obj_t blit_Rect_y(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Rect);

    if(n_args > 1) {
        int32_t y = mp_obj_get_int(args[1]);

        this_ptr->y = y;
    }

    return mp_obj_new_int(this_ptr->y);
}

mp_obj_t blit_Rect_w(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Rect);

    if(n_args > 1) {
        int32_t w = mp_obj_get_int(args[1]);

        this_ptr->w = w;
    }

    return mp_obj_new_int(this_ptr->w);
}

mp_obj_t blit_Rect_h(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Rect);

    if(n_args > 1) {
        int32_t h = mp_obj_get_int(args[1]);

        this_ptr->h = h;
    }

    return mp_obj_new_int(this_ptr->h);
}
