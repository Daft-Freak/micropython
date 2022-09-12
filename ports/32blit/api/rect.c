#include "rect.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Rect_size_obj, blit_Rect_size);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Rect_empty_obj, blit_Rect_empty);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Rect_contains_obj, blit_Rect_contains);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Rect_intersects_obj, blit_Rect_intersects);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Rect_intersection_obj, blit_Rect_intersection);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Rect_deflate_obj, blit_Rect_deflate);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Rect_inflate_obj, blit_Rect_inflate);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Rect_clamp_obj, blit_Rect_clamp);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Rect_tl_obj, blit_Rect_tl);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Rect_tr_obj, blit_Rect_tr);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Rect_bl_obj, blit_Rect_bl);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Rect_br_obj, blit_Rect_br);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Rect_center_obj, blit_Rect_center);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Rect_x_obj, 1, 2, blit_Rect_x);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Rect_y_obj, 1, 2, blit_Rect_y);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Rect_w_obj, 1, 2, blit_Rect_w);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Rect_h_obj, 1, 2, blit_Rect_h);

STATIC const mp_rom_map_elem_t blit_Rect_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_size), MP_ROM_PTR(&blit_Rect_size_obj) },
    { MP_ROM_QSTR(MP_QSTR_empty), MP_ROM_PTR(&blit_Rect_empty_obj) },
    { MP_ROM_QSTR(MP_QSTR_contains), MP_ROM_PTR(&blit_Rect_contains_obj) },
    { MP_ROM_QSTR(MP_QSTR_intersects), MP_ROM_PTR(&blit_Rect_intersects_obj) },
    { MP_ROM_QSTR(MP_QSTR_intersection), MP_ROM_PTR(&blit_Rect_intersection_obj) },
    { MP_ROM_QSTR(MP_QSTR_deflate), MP_ROM_PTR(&blit_Rect_deflate_obj) },
    { MP_ROM_QSTR(MP_QSTR_inflate), MP_ROM_PTR(&blit_Rect_inflate_obj) },
    { MP_ROM_QSTR(MP_QSTR_clamp), MP_ROM_PTR(&blit_Rect_clamp_obj) },
    { MP_ROM_QSTR(MP_QSTR_tl), MP_ROM_PTR(&blit_Rect_tl_obj) },
    { MP_ROM_QSTR(MP_QSTR_tr), MP_ROM_PTR(&blit_Rect_tr_obj) },
    { MP_ROM_QSTR(MP_QSTR_bl), MP_ROM_PTR(&blit_Rect_bl_obj) },
    { MP_ROM_QSTR(MP_QSTR_br), MP_ROM_PTR(&blit_Rect_br_obj) },
    { MP_ROM_QSTR(MP_QSTR_center), MP_ROM_PTR(&blit_Rect_center_obj) },
    { MP_ROM_QSTR(MP_QSTR_x), MP_ROM_PTR(&blit_Rect_x_obj) },
    { MP_ROM_QSTR(MP_QSTR_y), MP_ROM_PTR(&blit_Rect_y_obj) },
    { MP_ROM_QSTR(MP_QSTR_w), MP_ROM_PTR(&blit_Rect_w_obj) },
    { MP_ROM_QSTR(MP_QSTR_h), MP_ROM_PTR(&blit_Rect_h_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_Rect_locals_dict, blit_Rect_locals_dict_table);

const mp_obj_type_t blit_Rect_type = {
    { &mp_type_type },
    .name = MP_QSTR_Rect,
    .make_new = blit_Rect_make_new,
    .binary_op = blit_Rect_binary_op,
    .locals_dict = (mp_obj_dict_t*)&blit_Rect_locals_dict,
};
