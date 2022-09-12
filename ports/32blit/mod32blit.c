#include "mod32blit.h"

#include "api/buttonstate.h"
#include "api/enums.h"
#include "api/font.h"
#include "api/point.h"
#include "api/rect.h"
#include "api/surface.h"

// globals
STATIC mp_obj_t blit_init(void) {

    // TODO: should check that these exist
    MP_STATE_PORT(render_callback_obj) = mp_load_global(qstr_from_str("render"));
    MP_STATE_PORT(update_callback_obj) = mp_load_global(qstr_from_str("update"));

    return mp_const_none;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_0(blit_init_obj, blit_init);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_set_screen_mode_obj, 1, 2, blit_set_screen_mode);

STATIC const mp_rom_map_elem_t blit_module_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_blit) },

    // enums (types-ish)
    { MP_ROM_QSTR(MP_QSTR_Button), (mp_obj_t)&blit_Button_type },
    { MP_ROM_QSTR(MP_QSTR_PixelFormat), (mp_obj_t)&blit_PixelFormat_type },
    { MP_ROM_QSTR(MP_QSTR_ScreenMode), (mp_obj_t)&blit_ScreenMode_type },
    { MP_ROM_QSTR(MP_QSTR_SpriteTransform), (mp_obj_t)&blit_SpriteTransform_type },
    { MP_ROM_QSTR(MP_QSTR_TextAlign), (mp_obj_t)&blit_TextAlign_type },

    // types
    { MP_ROM_QSTR(MP_QSTR_ButtonState), (mp_obj_t)&blit_ButtonState_type },
    { MP_ROM_QSTR(MP_QSTR_Font), (mp_obj_t)&blit_Font_type },
    { MP_ROM_QSTR(MP_QSTR_Point), (mp_obj_t)&blit_Point_type },
    { MP_ROM_QSTR(MP_QSTR_Rect), (mp_obj_t)&blit_Rect_type },
    { MP_ROM_QSTR(MP_QSTR_Surface), (mp_obj_t)&blit_Surface_type },

    // functions
    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&blit_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_set_screen_mode), MP_ROM_PTR(&blit_set_screen_mode_obj) },

    // global vars
    { MP_ROM_QSTR(MP_QSTR_buttons), MP_ROM_PTR(&blit_buttons) },

    { MP_ROM_QSTR(MP_QSTR_minimal_font), MP_ROM_PTR(&blit_minimal_font) },

    { MP_ROM_QSTR(MP_QSTR_screen), MP_ROM_PTR(&blit_screen) },
};
STATIC MP_DEFINE_CONST_DICT(blit_module_globals, blit_module_globals_table);

const mp_obj_module_t blit_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&blit_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_blit, blit_module);
