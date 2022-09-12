#include "buttonstate.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_ButtonState_state_obj, 1, 2, blit_ButtonState_state);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_ButtonState_pressed_obj, 1, 2, blit_ButtonState_pressed);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_ButtonState_released_obj, 1, 2, blit_ButtonState_released);

STATIC const mp_rom_map_elem_t blit_ButtonState_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_state), MP_ROM_PTR(&blit_ButtonState_state_obj) },
    { MP_ROM_QSTR(MP_QSTR_pressed), MP_ROM_PTR(&blit_ButtonState_pressed_obj) },
    { MP_ROM_QSTR(MP_QSTR_released), MP_ROM_PTR(&blit_ButtonState_released_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_ButtonState_locals_dict, blit_ButtonState_locals_dict_table);

const mp_obj_type_t blit_ButtonState_type = {
    { &mp_type_type },
    .name = MP_QSTR_ButtonState,

    .locals_dict = (mp_obj_dict_t*)&blit_ButtonState_locals_dict,
};
