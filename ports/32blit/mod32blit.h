#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "py/runtime.h"

typedef struct ObjWrapper {
    mp_obj_base_t base;
    void *ptr;
} ObjWrapper;

typedef struct ConstObjWrapper {
    mp_obj_base_t base;
    const void *ptr;
} ConstObjWrapper;

typedef struct EmbedObjWrapper {
    mp_obj_base_t base;
    char v[]; // placeholder for the actual data
} EmbedObjWrapper;

#define blit_unwrap_obj(obj, type) (type *)((ObjWrapper *)MP_OBJ_TO_PTR(obj))->ptr
#define blit_unwrap_obj_val(obj, type) (type *)&((EmbedObjWrapper *)MP_OBJ_TO_PTR(obj))->v
#define blit_wrap_obj(obj_ptr, type) blit_wrap_obj_type(obj_ptr, &blit_##type##_type)

mp_obj_t blit_wrap_obj_type(void *obj_ptr, const mp_obj_type_t *type);

// globals
extern const ObjWrapper blit_buttons;

extern const ConstObjWrapper blit_fat_font;
extern const ConstObjWrapper blit_minimal_font;
extern const ConstObjWrapper blit_outline_font;

extern const ObjWrapper blit_screen;

mp_obj_t blit_set_screen_mode(size_t n_args, const mp_obj_t *args);

#ifdef __cplusplus
}
#endif
