#include "py/runtime.h"

STATIC mp_obj_t blit_init(void) {

    // TODO: should check that these exist
    MP_STATE_PORT(render_callback_obj) = mp_load_global(qstr_from_str("render"));
    MP_STATE_PORT(update_callback_obj) = mp_load_global(qstr_from_str("update"));

    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_0(blit_init_obj, blit_init);

STATIC const mp_rom_map_elem_t blit_module_globals_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_blit) },
    { MP_ROM_QSTR(MP_QSTR_init), MP_ROM_PTR(&blit_init_obj) },
};
STATIC MP_DEFINE_CONST_DICT(blit_module_globals, blit_module_globals_table);

const mp_obj_module_t blit_module = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&blit_module_globals,
};

MP_REGISTER_MODULE(MP_QSTR_blit, blit_module);
