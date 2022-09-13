#include "blit-helpers.hpp"

#include "api/point.h"
#include "api/rect.h"
#include "api/size.h"

using namespace blit;

struct blit_Point {
    mp_obj_base_t base;
    Point val;
};

struct blit_Rect {
    mp_obj_base_t base;
    Rect val;
};

struct blit_Size {
    mp_obj_base_t base;
    Size val;
};

// some of these may be actual types in future

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

// slightly custom constructor
mp_obj_t blit_Point_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 0, 2, false);

    auto p = m_new_obj(blit_Point);
    p->base.type = &blit_Point_type;

    if(n_args == 0)
        new(&p->val) Point();
    else if(n_args == 1)
        new(&p->val) Point(blit_obj_to_Point(args[0]));
    else // n_args == 2
        new(&p->val) Point(mp_obj_get_int(args[0]), mp_obj_get_int(args[1]));

    return MP_OBJ_FROM_PTR(p);
}

Point blit_obj_to_Point(mp_obj_t obj) {
    if (mp_obj_is_type(obj, &blit_Point_type)) {
        // real point
        auto p = (blit_Point *)MP_OBJ_TO_PTR(obj);
        return p->val;
    } else if (mp_obj_is_type(obj, &mp_type_tuple)) {
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
        mp_raise_TypeError("invalid type for point (expected Point or a tuple)");
    }

    return {};
}

mp_obj_t blit_obj_from_Point(Point p) {
    auto pp = m_new_obj(blit_Point);
    pp->base.type = &blit_Point_type;
    pp->val = p;

    return MP_OBJ_FROM_PTR(pp);
}

bool blit_obj_is_Point(mp_obj_t obj) {

    if(mp_obj_is_type(obj, &blit_Point_type))
        return true;

    return mp_obj_is_type(obj, &mp_type_tuple) && ((mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj))->len == 2;
}

mp_obj_t blit_Size_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 0, 2, false);

    auto p = m_new_obj(blit_Size);
    p->base.type = &blit_Size_type;

    if(n_args == 0)
        new(&p->val) Size();
    else if(n_args == 1)
        new(&p->val) Size(blit_obj_to_Size(args[0]));
    else // n_args == 2
        new(&p->val) Size(mp_obj_get_int(args[0]), mp_obj_get_int(args[1]));

    return MP_OBJ_FROM_PTR(p);
}

Size blit_obj_to_Size(mp_obj_t obj) {
    if (mp_obj_is_type(obj, &blit_Size_type)) {
        // real size
        auto p = (blit_Size *)MP_OBJ_TO_PTR(obj);
        return p->val;
    } else if (mp_obj_is_type(obj, &mp_type_tuple)) {
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
    auto ps = m_new_obj(blit_Size);
    ps->base.type = &blit_Size_type;
    ps->val = s;

    return MP_OBJ_FROM_PTR(ps);
}

mp_obj_t blit_Rect_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 0, 4, false);

    auto p = m_new_obj(blit_Rect);
    p->base.type = &blit_Rect_type;

    if(n_args == 0)
        new(&p->val) Rect();
    else if(n_args == 1)
        new(&p->val) Rect(blit_obj_to_Rect(args[0]));
    else if(n_args == 2 && blit_obj_is_Point(args[0])) {
        if(blit_obj_is_Point(args[1]))
            new(&p->val) Rect(blit_obj_to_Point(args[0]), blit_obj_to_Point(args[1]));
        else // size
            new(&p->val) Rect(blit_obj_to_Point(args[0]), blit_obj_to_Size(args[1]));
    } else if(n_args == 4)
        new(&p->val) Rect(mp_obj_get_int(args[0]), mp_obj_get_int(args[1]), mp_obj_get_int(args[2]), mp_obj_get_int(args[3]));
    else
        mp_raise_TypeError("invalid arguments");

    return MP_OBJ_FROM_PTR(p);
}

Rect blit_obj_to_Rect(mp_obj_t obj)  {
    if (mp_obj_is_type(obj, &blit_Rect_type)) {
        // real point
        auto p = (blit_Rect *)MP_OBJ_TO_PTR(obj);
        return p->val;
    } else if (mp_obj_is_type(obj, &mp_type_tuple)) {
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
    auto pr = m_new_obj(blit_Rect);
    pr->base.type = &blit_Rect_type;
    pr->val = r;

    return MP_OBJ_FROM_PTR(pr);
}

bool blit_obj_is_Rect(mp_obj_t obj) {
    if(mp_obj_is_type(obj, &blit_Rect_type))
        return true;

    return mp_obj_is_type(obj, &mp_type_tuple) && ((mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj))->len == 4;
}

Vec2 blit_obj_to_Vec2(mp_obj_t obj)  {
    if (mp_obj_is_type(obj, &mp_type_tuple)) {
        auto tuple = (mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj);

        if(tuple->len == 2) {
            return Vec2{
                mp_obj_get_float(tuple->items[0]),
                mp_obj_get_float(tuple->items[1])
            };
        } else {
            mp_raise_ValueError("vec2 tuples must contain 2 items");
        }
    } else {
        mp_raise_TypeError("invalid type for vec2 (expected a tuple)");
    }

    return Vec2();
}

mp_obj_t blit_obj_from_Vec2(Vec2 v) {
    mp_obj_t items[]{
        mp_obj_new_float(v.x),
        mp_obj_new_float(v.y),
    };

    return mp_obj_new_tuple(2, items);
}

bool blit_obj_is_Vec2(mp_obj_t obj) {
    return mp_obj_is_type(obj, &mp_type_tuple) && ((mp_obj_tuple_t *)MP_OBJ_TO_PTR(obj))->len == 2;
}
