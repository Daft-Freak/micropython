#include "mod32blit.h"

#include "api/buttonstate.h"
#include "api/font.h"
#include "api/surface.h"

#include "32blit.hpp"
#include "engine/api_private.hpp"

const ObjWrapper blit_buttons = {&blit_ButtonState_type, &blit::api.buttons}; // blit::buttons is a reference

const ConstObjWrapper blit_fat_font = {&blit_Font_type, &blit::fat_font};
const ConstObjWrapper blit_minimal_font = {&blit_Font_type, &blit::minimal_font};
const ConstObjWrapper blit_outline_font = {&blit_Font_type, &blit::outline_font};

const ObjWrapper blit_screen = {&blit_Surface_type, &blit::screen};

mp_obj_t blit_wrap_obj_type(void *obj_ptr, const mp_obj_type_t *type) {
    auto wrap = m_new_obj(ObjWrapper);
    wrap->base.type = type;
    wrap->ptr = obj_ptr; // ... probably leaking these ...

    return MP_OBJ_FROM_PTR(wrap);
}

mp_obj_t blit_set_screen_mode(size_t n_args, const mp_obj_t *args) {
    auto mode = blit::ScreenMode(mp_obj_get_int(args[0]));
    bool ret = true;

    if(n_args == 2)
        ret = blit::set_screen_mode(mode, blit::PixelFormat(mp_obj_get_int(args[1])));
    else
        blit::set_screen_mode(mode);

    return mp_obj_new_bool(ret);
}
