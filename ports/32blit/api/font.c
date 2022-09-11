#include "font.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Font_char_w_obj, 1, 1, blit_Font_char_w);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Font_char_h_obj, 1, 1, blit_Font_char_h);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Font_spacing_y_obj, 1, 1, blit_Font_spacing_y);

STATIC const mp_rom_map_elem_t blit_Font_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_char_w), MP_ROM_PTR(&blit_Font_char_w_obj) },
    { MP_ROM_QSTR(MP_QSTR_char_h), MP_ROM_PTR(&blit_Font_char_h_obj) },
    { MP_ROM_QSTR(MP_QSTR_spacing_y), MP_ROM_PTR(&blit_Font_spacing_y_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_Font_locals_dict, blit_Font_locals_dict_table);

const mp_obj_type_t blit_Font_type = {
    { &mp_type_type },
    .name = MP_QSTR_Font,
    //.make_new = blit_Font_make_new, // TODO
    .locals_dict = (mp_obj_dict_t*)&blit_Font_locals_dict,
};
