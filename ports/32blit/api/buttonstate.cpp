#include "buttonstate.h"

#include "../blit-helpers.hpp"

using namespace blit;

mp_obj_t blit_ButtonState_state(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], ButtonState);

    if(n_args > 1) {
        uint32_t state = mp_obj_get_int(args[1]);

        this_ptr->state = state;
    }

    return mp_obj_new_int(this_ptr->state);
}

mp_obj_t blit_ButtonState_pressed(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], ButtonState);

    if(n_args > 1) {
        uint32_t pressed = mp_obj_get_int(args[1]);

        this_ptr->pressed = pressed;
    }

    return mp_obj_new_int(this_ptr->pressed);
}

mp_obj_t blit_ButtonState_released(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], ButtonState);

    if(n_args > 1) {
        uint32_t released = mp_obj_get_int(args[1]);

        this_ptr->released = released;
    }

    return mp_obj_new_int(this_ptr->released);
}
