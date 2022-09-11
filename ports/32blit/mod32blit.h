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
#define blit_wrap_obj(obj_ptr, type) blit_wrap_obj_type(obj_ptr, &blit_##type##_type)

mp_obj_t blit_wrap_obj_type(void *obj_ptr, const mp_obj_type_t *type);

// globals
extern const ObjWrapper blit_screen;

#ifdef __cplusplus
}
#endif
