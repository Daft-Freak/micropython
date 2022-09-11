#include "point.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Point_x_obj, 1, 2, blit_Point_x);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Point_y_obj, 1, 2, blit_Point_y);

STATIC const mp_rom_map_elem_t blit_Point_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_x), MP_ROM_PTR(&blit_Point_x_obj) },
    { MP_ROM_QSTR(MP_QSTR_y), MP_ROM_PTR(&blit_Point_y_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_Point_locals_dict, blit_Point_locals_dict_table);

const mp_obj_type_t blit_Point_type = {
    { &mp_type_type },
    .name = MP_QSTR_Point,
    .make_new = blit_Point_make_new,
    .binary_op = blit_Point_binary_op,
    .locals_dict = (mp_obj_dict_t*)&blit_Point_locals_dict,
};
