#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "py/runtime.h"

typedef struct ObjWrapper {
    mp_obj_base_t base;
    void *ptr;
} ObjWrapper;

#define blit_unwrap_obj(obj, type) (type *)((ObjWrapper *)MP_OBJ_TO_PTR(obj))->ptr
#define blit_wrap_obj(obj, type) mp_const_none // TODO

// types

// Surface
mp_obj_t blit_Surface_set_pen(mp_obj_t self, mp_obj_t pen);
mp_obj_t blit_Surface_clear(mp_obj_t self);

extern const mp_obj_type_t blit_Surface_type;

// globals
extern const ObjWrapper blit_screen;

#ifdef __cplusplus
}
#endif
