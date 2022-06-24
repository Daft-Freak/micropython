#include "mod32blit.h"

#include "32blit.hpp"

using namespace blit;

Pen blit_obj_to_pen(mp_obj_t obj) {
    if (mp_obj_is_type(obj, &mp_type_tuple)) {
        auto tuple = (mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj);

        if(tuple->len == 1) {
            return {(int)mp_obj_get_int(tuple->items[0])};
        } else if(tuple->len == 3) {
            return {
                (int)mp_obj_get_int(tuple->items[0]),
                (int)mp_obj_get_int(tuple->items[1]),
                (int)mp_obj_get_int(tuple->items[2])
            };
        } else if(tuple->len == 4) {
            return {
                (int)mp_obj_get_int(tuple->items[0]),
                (int)mp_obj_get_int(tuple->items[1]),
                (int)mp_obj_get_int(tuple->items[2]),
                (int)mp_obj_get_int(tuple->items[3])
            };
        } else {
            mp_raise_ValueError("pen tuples must contain 1, 3 or 4 items");
        }
    } else {
        mp_raise_TypeError("invalid type for pen (expected a tuple)");
    }

    return {};
}

mp_obj_t blit_Surface_set_pen(mp_obj_t self, mp_obj_t pen) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    this_ptr->pen = blit_obj_to_pen(pen);
    return mp_const_none;
}

mp_obj_t blit_Surface_clear(mp_obj_t self) {
    auto this_ptr = blit_unwrap_obj(self, Surface);
    this_ptr->clear();
    return mp_const_none;
}


const ObjWrapper blit_screen = {&blit_Surface_type, &screen};
