#include "size.h"

#include "../blit-helpers.hpp"

using namespace blit;

mp_obj_t blit_Size_empty(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Size);

    auto ret = this_ptr->empty();
    return mp_obj_new_bool(ret);
}

mp_obj_t blit_Size_area(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj_val(self, Size);

    auto ret = this_ptr->area();
    return mp_obj_new_int(ret);
}

mp_obj_t blit_Size_contains(mp_obj_t self, mp_obj_t p_obj) {
    auto this_ptr = blit_unwrap_obj_val(self, Size);
    Point p = blit_obj_to_Point(p_obj);

    auto ret = this_ptr->contains(p);
    return mp_obj_new_bool(ret);
}

mp_obj_t blit_Size_binary_op(mp_binary_op_t op, mp_obj_t lhs, mp_obj_t rhs) {
    auto left_side = blit_unwrap_obj_val(lhs, Size);
    switch (op) {
        case MP_BINARY_OP_MULTIPLY:
        case MP_BINARY_OP_INPLACE_MULTIPLY:
        {
            float right_side = mp_obj_get_float(rhs);
            return blit_obj_from_Size(*left_side * right_side);
        }
        case MP_BINARY_OP_TRUE_DIVIDE:
        case MP_BINARY_OP_INPLACE_TRUE_DIVIDE:
        {
            float right_side = mp_obj_get_float(rhs);
            return blit_obj_from_Size(*left_side / right_side);
        }
        case MP_BINARY_OP_EQUAL:
        {
            if(blit_obj_is_Size(rhs)) {
                Size right_side = blit_obj_to_Size(rhs);
                return mp_obj_new_bool(*left_side == right_side);
            }
            return MP_OBJ_NULL;
        }
        case MP_BINARY_OP_NOT_EQUAL:
        {
            if(blit_obj_is_Size(rhs)) {
                Size right_side = blit_obj_to_Size(rhs);
                return mp_obj_new_bool(*left_side != right_side);
            }
            return MP_OBJ_NULL;
        }

        default:
            return MP_OBJ_NULL;
    }
}

mp_obj_t blit_Size_w(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Size);

    if(n_args > 1) {
        int32_t w = mp_obj_get_int(args[1]);

        this_ptr->w = w;
    }

    return mp_obj_new_int(this_ptr->w);
}

mp_obj_t blit_Size_h(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Size);

    if(n_args > 1) {
        int32_t h = mp_obj_get_int(args[1]);

        this_ptr->h = h;
    }

    return mp_obj_new_int(this_ptr->h);
}
