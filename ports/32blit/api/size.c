#include "size.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Size_empty_obj, blit_Size_empty);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Size_area_obj, blit_Size_area);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Size_contains_obj, blit_Size_contains);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Size_w_obj, 1, 2, blit_Size_w);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Size_h_obj, 1, 2, blit_Size_h);

STATIC const mp_rom_map_elem_t blit_Size_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_empty), MP_ROM_PTR(&blit_Size_empty_obj) },
    { MP_ROM_QSTR(MP_QSTR_area), MP_ROM_PTR(&blit_Size_area_obj) },
    { MP_ROM_QSTR(MP_QSTR_contains), MP_ROM_PTR(&blit_Size_contains_obj) },
    { MP_ROM_QSTR(MP_QSTR_w), MP_ROM_PTR(&blit_Size_w_obj) },
    { MP_ROM_QSTR(MP_QSTR_h), MP_ROM_PTR(&blit_Size_h_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_Size_locals_dict, blit_Size_locals_dict_table);

const mp_obj_type_t blit_Size_type = {
    { &mp_type_type },
    .name = MP_QSTR_Size,
    .make_new = blit_Size_make_new,
    .binary_op = blit_Size_binary_op,
    .locals_dict = (mp_obj_dict_t*)&blit_Size_locals_dict,
};
