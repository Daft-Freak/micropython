#include "enums.h"

STATIC const mp_rom_map_elem_t blit_Button_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_DPAD_LEFT), MP_ROM_INT(1) },
    { MP_ROM_QSTR(MP_QSTR_DPAD_RIGHT), MP_ROM_INT(2) },
    { MP_ROM_QSTR(MP_QSTR_DPAD_UP), MP_ROM_INT(4) },
    { MP_ROM_QSTR(MP_QSTR_DPAD_DOWN), MP_ROM_INT(8) },
    { MP_ROM_QSTR(MP_QSTR_A), MP_ROM_INT(16) },
    { MP_ROM_QSTR(MP_QSTR_B), MP_ROM_INT(32) },
    { MP_ROM_QSTR(MP_QSTR_X), MP_ROM_INT(64) },
    { MP_ROM_QSTR(MP_QSTR_Y), MP_ROM_INT(128) },
    { MP_ROM_QSTR(MP_QSTR_MENU), MP_ROM_INT(256) },
    { MP_ROM_QSTR(MP_QSTR_HOME), MP_ROM_INT(512) },
    { MP_ROM_QSTR(MP_QSTR_JOYSTICK), MP_ROM_INT(1024) },
};

STATIC MP_DEFINE_CONST_DICT(blit_Button_locals_dict, blit_Button_locals_dict_table);

const mp_obj_type_t blit_Button_type = {
    { &mp_type_type },
    .name = MP_QSTR_Button,
    .locals_dict = (mp_obj_dict_t*)&blit_Button_locals_dict,
};

STATIC const mp_rom_map_elem_t blit_PixelFormat_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_RGB), MP_ROM_INT(0) },
    { MP_ROM_QSTR(MP_QSTR_RGBA), MP_ROM_INT(1) },
    { MP_ROM_QSTR(MP_QSTR_P), MP_ROM_INT(2) },
    { MP_ROM_QSTR(MP_QSTR_M), MP_ROM_INT(3) },
    { MP_ROM_QSTR(MP_QSTR_RGB565), MP_ROM_INT(4) },
};

STATIC MP_DEFINE_CONST_DICT(blit_PixelFormat_locals_dict, blit_PixelFormat_locals_dict_table);

const mp_obj_type_t blit_PixelFormat_type = {
    { &mp_type_type },
    .name = MP_QSTR_PixelFormat,
    .locals_dict = (mp_obj_dict_t*)&blit_PixelFormat_locals_dict,
};

STATIC const mp_rom_map_elem_t blit_ScreenMode_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_lores), MP_ROM_INT(0) },
    { MP_ROM_QSTR(MP_QSTR_hires), MP_ROM_INT(1) },
};

STATIC MP_DEFINE_CONST_DICT(blit_ScreenMode_locals_dict, blit_ScreenMode_locals_dict_table);

const mp_obj_type_t blit_ScreenMode_type = {
    { &mp_type_type },
    .name = MP_QSTR_ScreenMode,
    .locals_dict = (mp_obj_dict_t*)&blit_ScreenMode_locals_dict,
};

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

