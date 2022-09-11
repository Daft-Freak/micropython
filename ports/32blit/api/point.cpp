#include "point.h"

#include "../blit-helpers.hpp"

using namespace blit;

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
