#include "vec2.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Vec2_normalize_obj, blit_Vec2_normalize);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Vec2_length_obj, blit_Vec2_length);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Vec2_cross_obj, blit_Vec2_cross);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Vec2_dot_obj, blit_Vec2_dot);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Vec2_rotate_obj, blit_Vec2_rotate);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Vec2_angle_obj, blit_Vec2_angle);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Vec2_x_obj, 1, 2, blit_Vec2_x);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Vec2_y_obj, 1, 2, blit_Vec2_y);

STATIC const mp_rom_map_elem_t blit_Vec2_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_normalize), MP_ROM_PTR(&blit_Vec2_normalize_obj) },
    { MP_ROM_QSTR(MP_QSTR_length), MP_ROM_PTR(&blit_Vec2_length_obj) },
    { MP_ROM_QSTR(MP_QSTR_cross), MP_ROM_PTR(&blit_Vec2_cross_obj) },
    { MP_ROM_QSTR(MP_QSTR_dot), MP_ROM_PTR(&blit_Vec2_dot_obj) },
    { MP_ROM_QSTR(MP_QSTR_rotate), MP_ROM_PTR(&blit_Vec2_rotate_obj) },
    { MP_ROM_QSTR(MP_QSTR_angle), MP_ROM_PTR(&blit_Vec2_angle_obj) },
    { MP_ROM_QSTR(MP_QSTR_x), MP_ROM_PTR(&blit_Vec2_x_obj) },
    { MP_ROM_QSTR(MP_QSTR_y), MP_ROM_PTR(&blit_Vec2_y_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_Vec2_locals_dict, blit_Vec2_locals_dict_table);

const mp_obj_type_t blit_Vec2_type = {
    { &mp_type_type },
    .name = MP_QSTR_Vec2,
    .make_new = blit_Vec2_make_new,
    .binary_op = blit_Vec2_binary_op,
    .locals_dict = (mp_obj_dict_t*)&blit_Vec2_locals_dict,
};
