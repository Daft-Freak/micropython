#pragma once

extern "C" {
#include "py/runtime.h"
}

#ifndef NO_QSTR // 32blit include path is missing
#include "32blit.hpp"
#endif

blit::Pen blit_obj_to_Pen(mp_obj_t obj);
mp_obj_t blit_obj_from_Pen(blit::Pen p);

blit::Point blit_obj_to_Point(mp_obj_t obj);
mp_obj_t blit_obj_from_Point(blit::Point p);
bool blit_obj_is_Point(mp_obj_t obj);

blit::Size blit_obj_to_Size(mp_obj_t obj);
mp_obj_t blit_obj_from_Size(blit::Size s);

blit::Rect blit_obj_to_Rect(mp_obj_t obj);
mp_obj_t blit_obj_from_Rect(blit::Rect r);
bool blit_obj_is_Rect(mp_obj_t obj);

blit::Vec2 blit_obj_to_Vec2(mp_obj_t obj);
mp_obj_t blit_obj_from_Vec2(blit::Vec2 v);
bool blit_obj_is_Vec2(mp_obj_t obj);
