#include "point.h"

#include "../blit-helpers.hpp"

using namespace blit;

mp_obj_t blit_Point_binary_op(mp_binary_op_t op, mp_obj_t lhs, mp_obj_t rhs) {
    auto left_side = blit_unwrap_obj_val(lhs, Point);
    switch (op) {
        case MP_BINARY_OP_ADD:
        case MP_BINARY_OP_INPLACE_ADD:
        {
            auto right_side = blit_unwrap_obj_val(rhs, Point);
            return blit_obj_from_Point(*left_side + *right_side);
        }
        case MP_BINARY_OP_SUBTRACT:
        case MP_BINARY_OP_INPLACE_SUBTRACT:
        {
            auto right_side = blit_unwrap_obj_val(rhs, Point);
            return blit_obj_from_Point(*left_side - *right_side);
        }
        case MP_BINARY_OP_MULTIPLY:
        case MP_BINARY_OP_INPLACE_MULTIPLY:
        {
            float right_side = mp_obj_get_float(rhs);
            return blit_obj_from_Point(*left_side * right_side);
        }
        case MP_BINARY_OP_TRUE_DIVIDE:
        case MP_BINARY_OP_INPLACE_TRUE_DIVIDE:
        {
            int right_side = mp_obj_get_int(rhs);
            return blit_obj_from_Point(*left_side / right_side);
        }

        default:
            return MP_OBJ_NULL;
    }
}

mp_obj_t blit_Point_x(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Point);

    if(n_args > 1) {
        int32_t x = mp_obj_get_int(args[1]);

        this_ptr->x = x;
    }

    return mp_obj_new_int(this_ptr->x);
}

mp_obj_t blit_Point_y(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj_val(args[0], Point);

    if(n_args > 1) {
        int32_t y = mp_obj_get_int(args[1]);

        this_ptr->y = y;
    }

    return mp_obj_new_int(this_ptr->y);
}
