#pragma once

#include "../mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_ButtonState_state(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_ButtonState_pressed(size_t n_args, const mp_obj_t *args);
mp_obj_t blit_ButtonState_released(size_t n_args, const mp_obj_t *args);

extern const mp_obj_type_t blit_ButtonState_type;

#ifdef __cplusplus
}
#endif
