#include "mod32blit.h"

#include "api/surface.h"

#include "32blit.hpp"

const ObjWrapper blit_screen = {&blit_Surface_type, &blit::screen};

mp_obj_t blit_wrap_obj_type(void *obj_ptr, const mp_obj_type_t *type) {
    auto wrap = m_new_obj(ObjWrapper);
    wrap->base.type = type;
    wrap->ptr = obj_ptr; // ... probably leaking these ...

    return MP_OBJ_FROM_PTR(wrap);
}
