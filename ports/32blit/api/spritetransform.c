#include "spritetransform.h"

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
