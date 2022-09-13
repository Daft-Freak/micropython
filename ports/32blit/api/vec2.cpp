#include "vec2.h"

#include "../blit-helpers.hpp"

using namespace blit;

mp_obj_t blit_Vec2_normalize(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Vec2);

    this_ptr->normalize();
    return mp_const_none;
}

mp_obj_t blit_Vec2_length(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Vec2);

    auto ret = this_ptr->length();
    return mp_obj_new_float(ret);
}

mp_obj_t blit_Vec2_cross(mp_obj_t self, mp_obj_t a_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Vec2);
    Vec2 a = blit_obj_to_Vec2(a_obj);

    auto ret = this_ptr->cross(a);
    return mp_obj_new_float(ret);
}

mp_obj_t blit_Vec2_dot(mp_obj_t self, mp_obj_t a_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Vec2);
    Vec2 a = blit_obj_to_Vec2(a_obj);

    auto ret = this_ptr->dot(a);
    return mp_obj_new_float(ret);
}

mp_obj_t blit_Vec2_rotate(mp_obj_t self, mp_obj_t a_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Vec2);
    float a = mp_obj_get_float(a_obj);

    this_ptr->rotate(a);
    return mp_const_none;
}

mp_obj_t blit_Vec2_angle(mp_obj_t self, mp_obj_t o_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Vec2);
    Vec2 o = blit_obj_to_Vec2(o_obj);

    auto ret = this_ptr->angle(o);
    return mp_obj_new_float(ret);
}

mp_obj_t blit_Vec2_binary_op(mp_binary_op_t op, mp_obj_t lhs, mp_obj_t rhs) {
    auto left_side = blit_unwrap_obj_val(lhs, Vec2);
    switch (op) {
        case MP_BINARY_OP_ADD:
        case MP_BINARY_OP_INPLACE_ADD:
        {
            auto right_side = blit_unwrap_obj_val(rhs, Vec2);
            return blit_obj_from_Vec2(*left_side + *right_side);
        }
        case MP_BINARY_OP_SUBTRACT:
        case MP_BINARY_OP_INPLACE_SUBTRACT:
        {
            auto right_side = blit_unwrap_obj_val(rhs, Vec2);
            return blit_obj_from_Vec2(*left_side - *right_side);
        }
        case MP_BINARY_OP_MULTIPLY:
        case MP_BINARY_OP_INPLACE_MULTIPLY:
        {
            if(mp_obj_is_float(rhs)) {
                float right_side = mp_obj_get_float(rhs);
                return blit_obj_from_Vec2(*left_side * right_side);
            }
            if(blit_obj_is_Vec2(rhs)) {
                auto right_side = blit_unwrap_obj_val(rhs, Vec2);
                return blit_obj_from_Vec2(*left_side * *right_side);
            }
            return MP_OBJ_NULL;
        }
        case MP_BINARY_OP_TRUE_DIVIDE:
        case MP_BINARY_OP_INPLACE_TRUE_DIVIDE:
        {
            float right_side = mp_obj_get_float(rhs);
            return blit_obj_from_Vec2(*left_side / right_side);
        }

        default:
            return MP_OBJ_NULL;
    }
}

mp_obj_t blit_Vec2_x(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Vec2);

    if(n_args > 1) {
        float x = mp_obj_get_float(args[1]);

        this_ptr->x = x;
    }

    return mp_obj_new_float(this_ptr->x);
}

mp_obj_t blit_Vec2_y(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Vec2);

    if(n_args > 1) {
        float y = mp_obj_get_float(args[1]);

        this_ptr->y = y;
    }

    return mp_obj_new_float(this_ptr->y);
}
