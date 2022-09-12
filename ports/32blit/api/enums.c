#include "enums.h"

STATIC const mp_rom_map_elem_t blit_SpriteTransform_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_NONE), MP_ROM_INT(0) },
    { MP_ROM_QSTR(MP_QSTR_HORIZONTAL), MP_ROM_INT(1) },
    { MP_ROM_QSTR(MP_QSTR_VERTICAL), MP_ROM_INT(2) },
    { MP_ROM_QSTR(MP_QSTR_XYSWAP), MP_ROM_INT(4) },
    { MP_ROM_QSTR(MP_QSTR_R90), MP_ROM_INT(5) },
    { MP_ROM_QSTR(MP_QSTR_R180), MP_ROM_INT(3) },
    { MP_ROM_QSTR(MP_QSTR_R270), MP_ROM_INT(6) },
};

STATIC MP_DEFINE_CONST_DICT(blit_SpriteTransform_locals_dict, blit_SpriteTransform_locals_dict_table);

const mp_obj_type_t blit_SpriteTransform_type = {
    { &mp_type_type },
    .name = MP_QSTR_SpriteTransform,
    .locals_dict = (mp_obj_dict_t*)&blit_SpriteTransform_locals_dict,
};
STATIC const mp_rom_map_elem_t blit_TextAlign_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_left), MP_ROM_INT(0) },
    { MP_ROM_QSTR(MP_QSTR_center_h), MP_ROM_INT(4) },
    { MP_ROM_QSTR(MP_QSTR_right), MP_ROM_INT(8) },
    { MP_ROM_QSTR(MP_QSTR_top), MP_ROM_INT(0) },
    { MP_ROM_QSTR(MP_QSTR_center_v), MP_ROM_INT(1) },
    { MP_ROM_QSTR(MP_QSTR_bottom), MP_ROM_INT(2) },
    { MP_ROM_QSTR(MP_QSTR_top_left), MP_ROM_INT(0) },
    { MP_ROM_QSTR(MP_QSTR_center_left), MP_ROM_INT(1) },
    { MP_ROM_QSTR(MP_QSTR_bottom_left), MP_ROM_INT(2) },
    { MP_ROM_QSTR(MP_QSTR_top_center), MP_ROM_INT(4) },
    { MP_ROM_QSTR(MP_QSTR_center_center), MP_ROM_INT(5) },
    { MP_ROM_QSTR(MP_QSTR_bottom_center), MP_ROM_INT(6) },
    { MP_ROM_QSTR(MP_QSTR_top_right), MP_ROM_INT(8) },
    { MP_ROM_QSTR(MP_QSTR_center_right), MP_ROM_INT(9) },
    { MP_ROM_QSTR(MP_QSTR_bottom_right), MP_ROM_INT(10) },
};

STATIC MP_DEFINE_CONST_DICT(blit_TextAlign_locals_dict, blit_TextAlign_locals_dict_table);

const mp_obj_type_t blit_TextAlign_type = {
    { &mp_type_type },
    .name = MP_QSTR_TextAlign,
    .locals_dict = (mp_obj_dict_t*)&blit_TextAlign_locals_dict,
};
