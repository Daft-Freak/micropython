#pragma once
extern "C" {
#include "py/runtime.h"
}

#include "32blit.hpp"

blit::Pen blit_obj_to_Pen(mp_obj_t obj);
mp_obj_t blit_obj_from_Pen(blit::Pen p);

blit::Point blit_obj_to_Point(mp_obj_t obj);
mp_obj_t blit_obj_from_Point(blit::Point p);

blit::Size blit_obj_to_Size(mp_obj_t obj);
mp_obj_t blit_obj_from_Size(blit::Size s);

blit::Rect blit_obj_to_Rect(mp_obj_t obj);
mp_obj_t blit_obj_from_Rect(blit::Rect r);
