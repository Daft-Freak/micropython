#include "font.h"

#include "../blit-helpers.hpp"

using namespace blit;

mp_obj_t blit_Font_char_w(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Font);
    return mp_obj_new_int(this_ptr->char_w);
}

mp_obj_t blit_Font_char_h(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Font);
    return mp_obj_new_int(this_ptr->char_h);
}

mp_obj_t blit_Font_spacing_y(size_t n_args, const mp_obj_t *args) {
    auto this_ptr = blit_unwrap_obj(args[0], Font);
    return mp_obj_new_int(this_ptr->spacing_y);
}
