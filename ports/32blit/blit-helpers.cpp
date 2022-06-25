#include "blit-helpers.hpp"

using namespace blit;

// some of these may be an actual types in future

Pen blit_obj_to_Pen(mp_obj_t obj) {
    if (mp_obj_is_type(obj, &mp_type_tuple)) {
        auto tuple = (mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj);

        if(tuple->len == 1) {
            return {(int)mp_obj_get_int(tuple->items[0])};
        } else if(tuple->len == 3) {
            return {
                (int)mp_obj_get_int(tuple->items[0]),
                (int)mp_obj_get_int(tuple->items[1]),
                (int)mp_obj_get_int(tuple->items[2])
            };
        } else if(tuple->len == 4) {
            return {
                (int)mp_obj_get_int(tuple->items[0]),
                (int)mp_obj_get_int(tuple->items[1]),
                (int)mp_obj_get_int(tuple->items[2]),
                (int)mp_obj_get_int(tuple->items[3])
            };
        } else {
            mp_raise_ValueError("pen tuples must contain 1, 3 or 4 items");
        }
    } else {
        mp_raise_TypeError("invalid type for pen (expected a tuple)");
    }

    return {};
}

mp_obj_t blit_obj_from_Pen(Pen p) {
    mp_obj_t items[]{
        mp_obj_new_int(p.r),
        mp_obj_new_int(p.g),
        mp_obj_new_int(p.b),
        mp_obj_new_int(p.a),
    };

    return mp_obj_new_tuple(4, items);
}

Point blit_obj_to_Point(mp_obj_t obj) {
    if (mp_obj_is_type(obj, &mp_type_tuple)) {
        auto tuple = (mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj);

        if(tuple->len == 2) {
            return {
                (int32_t)mp_obj_get_int(tuple->items[0]),
                (int32_t)mp_obj_get_int(tuple->items[1])
            };
        } else {
            mp_raise_ValueError("point tuples must contain 2 items");
        }
    } else {
        mp_raise_TypeError("invalid type for point (expected a tuple)");
    }

    return {};
}

mp_obj_t blit_obj_from_Point(Point p) {
    mp_obj_t items[]{
        mp_obj_new_int(p.x),
        mp_obj_new_int(p.y),
    };

    return mp_obj_new_tuple(2, items);
}

Size blit_obj_to_Size(mp_obj_t obj) {
    if (mp_obj_is_type(obj, &mp_type_tuple)) {
        auto tuple = (mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj);

        if(tuple->len == 2) {
            return {
                (int32_t)mp_obj_get_int(tuple->items[0]),
                (int32_t)mp_obj_get_int(tuple->items[1])
            };
        } else {
            mp_raise_ValueError("size tuples must contain 2 items");
        }
    } else {
        mp_raise_TypeError("invalid type for size (expected a tuple)");
    }

    return {};
}

mp_obj_t blit_obj_from_Size(Size s) {
    mp_obj_t items[]{
        mp_obj_new_int(s.w),
        mp_obj_new_int(s.h),
    };

    return mp_obj_new_tuple(2, items);
}

Rect blit_obj_to_Rect(mp_obj_t obj)  {
    if (mp_obj_is_type(obj, &mp_type_tuple)) {
        auto tuple = (mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj);

        // TODO: point/size pair?
        if(tuple->len == 4) {
            return {
                (int32_t)mp_obj_get_int(tuple->items[0]),
                (int32_t)mp_obj_get_int(tuple->items[1]),
                (int32_t)mp_obj_get_int(tuple->items[2]),
                (int32_t)mp_obj_get_int(tuple->items[3])
            };
        } else {
            mp_raise_ValueError("rect tuples must contain 4 items");
        }
    } else {
        mp_raise_TypeError("invalid type for rect (expected a tuple)");
    }

    return {};
}

mp_obj_t blit_obj_from_Rect(Rect r) {
    mp_obj_t items[]{
        mp_obj_new_int(r.x),
        mp_obj_new_int(r.y),
        mp_obj_new_int(r.w),
        mp_obj_new_int(r.h),
    };

    return mp_obj_new_tuple(4, items);
}

