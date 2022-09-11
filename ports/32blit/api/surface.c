#include "surface.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Surface_load_obj, blit_Surface_load);
STATIC MP_DEFINE_CONST_STATICMETHOD_OBJ(blit_Surface_load_static_obj, MP_ROM_PTR(&blit_Surface_load_obj));
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Surface_save_obj, blit_Surface_save);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Surface_clear_obj, blit_Surface_clear);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Surface_pixel_obj, blit_Surface_pixel);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(blit_Surface_v_span_obj, blit_Surface_v_span);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(blit_Surface_h_span_obj, blit_Surface_h_span);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Surface_rectangle_obj, blit_Surface_rectangle);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(blit_Surface_circle_obj, blit_Surface_circle);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(blit_Surface_line_obj, blit_Surface_line);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_triangle_obj, 4, 4, blit_Surface_triangle);
STATIC MP_DEFINE_CONST_FUN_OBJ_KW(blit_Surface_text_obj, 4, blit_Surface_text);
STATIC MP_DEFINE_CONST_FUN_OBJ_KW(blit_Surface_measure_text_obj, 3, blit_Surface_measure_text);
STATIC MP_DEFINE_CONST_FUN_OBJ_KW(blit_Surface_wrap_text_obj, 4, blit_Surface_wrap_text);
STATIC MP_DEFINE_CONST_FUN_OBJ_KW(blit_Surface_blit_obj, 4, blit_Surface_blit);
STATIC MP_DEFINE_CONST_FUN_OBJ_KW(blit_Surface_stretch_blit_obj, 4, blit_Surface_stretch_blit);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_stretch_blit_vspan_obj, 6, 6, blit_Surface_stretch_blit_vspan);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_Surface_watermark_obj, blit_Surface_watermark);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_Surface_sprite_bounds_obj, blit_Surface_sprite_bounds);
STATIC MP_DEFINE_CONST_FUN_OBJ_KW(blit_Surface_sprite_obj, 3, blit_Surface_sprite);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_bounds_obj, 1, 2, blit_Surface_bounds);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_clip_obj, 1, 2, blit_Surface_clip);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_alpha_obj, 1, 2, blit_Surface_alpha);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_pen_obj, 1, 2, blit_Surface_pen);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_mask_obj, 1, 2, blit_Surface_mask);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_sprites_obj, 1, 2, blit_Surface_sprites);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_transparent_index_obj, 1, 2, blit_Surface_transparent_index);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_rows_obj, 1, 2, blit_Surface_rows);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_Surface_cols_obj, 1, 2, blit_Surface_cols);

STATIC const mp_rom_map_elem_t blit_Surface_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_load), MP_ROM_PTR(&blit_Surface_load_static_obj) },
    { MP_ROM_QSTR(MP_QSTR_save), MP_ROM_PTR(&blit_Surface_save_obj) },
    { MP_ROM_QSTR(MP_QSTR_clear), MP_ROM_PTR(&blit_Surface_clear_obj) },
    { MP_ROM_QSTR(MP_QSTR_pixel), MP_ROM_PTR(&blit_Surface_pixel_obj) },
    { MP_ROM_QSTR(MP_QSTR_v_span), MP_ROM_PTR(&blit_Surface_v_span_obj) },
    { MP_ROM_QSTR(MP_QSTR_h_span), MP_ROM_PTR(&blit_Surface_h_span_obj) },
    { MP_ROM_QSTR(MP_QSTR_rectangle), MP_ROM_PTR(&blit_Surface_rectangle_obj) },
    { MP_ROM_QSTR(MP_QSTR_circle), MP_ROM_PTR(&blit_Surface_circle_obj) },
    { MP_ROM_QSTR(MP_QSTR_line), MP_ROM_PTR(&blit_Surface_line_obj) },
    { MP_ROM_QSTR(MP_QSTR_triangle), MP_ROM_PTR(&blit_Surface_triangle_obj) },
    { MP_ROM_QSTR(MP_QSTR_text), MP_ROM_PTR(&blit_Surface_text_obj) },
    { MP_ROM_QSTR(MP_QSTR_measure_text), MP_ROM_PTR(&blit_Surface_measure_text_obj) },
    { MP_ROM_QSTR(MP_QSTR_wrap_text), MP_ROM_PTR(&blit_Surface_wrap_text_obj) },
    { MP_ROM_QSTR(MP_QSTR_blit), MP_ROM_PTR(&blit_Surface_blit_obj) },
    { MP_ROM_QSTR(MP_QSTR_stretch_blit), MP_ROM_PTR(&blit_Surface_stretch_blit_obj) },
    { MP_ROM_QSTR(MP_QSTR_stretch_blit_vspan), MP_ROM_PTR(&blit_Surface_stretch_blit_vspan_obj) },
    { MP_ROM_QSTR(MP_QSTR_watermark), MP_ROM_PTR(&blit_Surface_watermark_obj) },
    { MP_ROM_QSTR(MP_QSTR_sprite_bounds), MP_ROM_PTR(&blit_Surface_sprite_bounds_obj) },
    { MP_ROM_QSTR(MP_QSTR_sprite), MP_ROM_PTR(&blit_Surface_sprite_obj) },
    { MP_ROM_QSTR(MP_QSTR_bounds), MP_ROM_PTR(&blit_Surface_bounds_obj) },
    { MP_ROM_QSTR(MP_QSTR_clip), MP_ROM_PTR(&blit_Surface_clip_obj) },
    { MP_ROM_QSTR(MP_QSTR_alpha), MP_ROM_PTR(&blit_Surface_alpha_obj) },
    { MP_ROM_QSTR(MP_QSTR_pen), MP_ROM_PTR(&blit_Surface_pen_obj) },
    { MP_ROM_QSTR(MP_QSTR_mask), MP_ROM_PTR(&blit_Surface_mask_obj) },
    { MP_ROM_QSTR(MP_QSTR_sprites), MP_ROM_PTR(&blit_Surface_sprites_obj) },
    { MP_ROM_QSTR(MP_QSTR_transparent_index), MP_ROM_PTR(&blit_Surface_transparent_index_obj) },
    { MP_ROM_QSTR(MP_QSTR_rows), MP_ROM_PTR(&blit_Surface_rows_obj) },
    { MP_ROM_QSTR(MP_QSTR_cols), MP_ROM_PTR(&blit_Surface_cols_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_Surface_locals_dict, blit_Surface_locals_dict_table);

const mp_obj_type_t blit_Surface_type = {
    { &mp_type_type },
    .name = MP_QSTR_Surface,
    //.make_new = blit_Surface_make_new, // TODO
    .locals_dict = (mp_obj_dict_t*)&blit_Surface_locals_dict,
};
