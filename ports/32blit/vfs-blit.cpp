extern "C"{
#include "py/mperrno.h"
#include "py/stream.h"
#include "extmod/vfs.h"
}

#include "vfs-blit.h"

#include "blit-helpers.hpp"
#include "engine/api_private.hpp"

using namespace blit;

struct blit_vfs {
    mp_obj_base_t base;
};

struct blit_vfs_file {
    mp_obj_base_t base;
    void *fh;
    uint32_t off;
};

mp_obj_t blit_vfs_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    auto p = m_new_obj(blit_vfs);
    p->base.type = &blit_vfs_type;

    return MP_OBJ_FROM_PTR(p);
}

mp_obj_t blit_vfs_mount(mp_obj_t self, mp_obj_t readonly, mp_obj_t mkfs) {
    // auto vfs = (blit_vfs *)MP_OBJ_TO_PTR(self);

    // readonly ignored

    if (mp_obj_is_true(mkfs)) {
        mp_raise_OSError(MP_EPERM);
    }
    return mp_const_none;
}

mp_obj_t blit_vfs_umount(mp_obj_t self) {
    return mp_const_none;
}

static mp_obj_t blit_vfs_file_open(const mp_obj_type_t *type, mp_obj_t path_obj, mp_obj_t mode_obj) {
    auto file = m_new_obj(blit_vfs_file);
    const char *mode = mp_obj_str_get_str(mode_obj);

    int blit_mode = 0;
    while (*mode) {
        switch (*mode++) {
            case 'r':
                blit_mode = OpenMode::read;
                break;
            case 'w':
                blit_mode = OpenMode::write;
                break;
            //case 'a': // no append in blit api...
            case '+':
                blit_mode = OpenMode::read | OpenMode::write;
                break;
//#if MICROPY_PY_IO_FILEIO...

        }
    }

    file->base.type = type;

    auto path = mp_obj_str_get_str(path_obj);
    file->fh = api.open_file(path, blit_mode);
    file->off = 0;

    if(!file->fh)
        mp_raise_OSError(MP_ENOENT);

    return MP_OBJ_FROM_PTR(file);
}

mp_obj_t blit_vfs_stat(mp_obj_t self, mp_obj_t path_obj) {
    auto path = mp_obj_str_get_str(path_obj);

    // TODO: we don't have a stat API, so all we can do is check if it's a file/dir
    mp_int_t mode = 0;
    if (api.directory_exists(path))
        mode |= MP_S_IFDIR;
    else if(api.file_exists(path))
        mode |= MP_S_IFREG;
    else
        mp_raise_OSError(MP_ENOENT);

    auto t = (mp_obj_tuple_t *)mp_obj_new_tuple(10, nullptr);

    t->items[0] = MP_OBJ_NEW_SMALL_INT(mode); // st_mode
    t->items[1] = MP_OBJ_NEW_SMALL_INT(0); // st_ino
    t->items[2] = MP_OBJ_NEW_SMALL_INT(0); // st_dev
    t->items[3] = MP_OBJ_NEW_SMALL_INT(0); // st_nlink
    t->items[4] = MP_OBJ_NEW_SMALL_INT(0); // st_uid
    t->items[5] = MP_OBJ_NEW_SMALL_INT(0); // st_gid
    t->items[6] = MP_OBJ_NEW_SMALL_INT(0); // st_size
    t->items[7] = MP_OBJ_NEW_SMALL_INT(0); // st_atime
    t->items[8] = MP_OBJ_NEW_SMALL_INT(0); // st_mtime
    t->items[9] = MP_OBJ_NEW_SMALL_INT(0); // st_ctime

    return MP_OBJ_FROM_PTR(t);
}

mp_obj_t blit_vfs_open(mp_obj_t self, mp_obj_t path_obj, mp_obj_t mode_obj) {
    return blit_vfs_file_open(&blit_vfs_textio_type, path_obj, mode_obj);
}

// file
mp_obj_t blit_vfs_file_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_file, MP_ARG_OBJ | MP_ARG_REQUIRED, {.u_rom_obj = MP_ROM_NONE} },
        { MP_QSTR_mode, MP_ARG_OBJ, {.u_rom_obj = MP_ROM_QSTR(MP_QSTR_r)} },
    };

    mp_arg_val_t arg_vals[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, args, MP_ARRAY_SIZE(allowed_args), allowed_args, arg_vals);
    return blit_vfs_file_open(type, arg_vals[0].u_obj, arg_vals[1].u_obj);
}

mp_uint_t blit_vfs_file_read(mp_obj_t file_obj, void *buf, mp_uint_t size, int *errcode) {
    auto file = (blit_vfs_file *)MP_OBJ_TO_PTR(file_obj);

    auto r = api.read_file(file->fh, file->off, size, (char *)buf);

    if(r < 0) {
        *errcode = MP_EIO;
        return MP_STREAM_ERROR;
    }

    file->off += size;

    return r;
}

mp_uint_t blit_vfs_file_write(mp_obj_t file_obj, const void *buf, mp_uint_t size, int *errcode) {
    auto file = (blit_vfs_file *)MP_OBJ_TO_PTR(file_obj);

    auto r = api.write_file(file->fh, file->off, size, (const char *)buf);

    if(r < 0) {
        *errcode = MP_EIO;
        return MP_STREAM_ERROR;
    }

    file->off += size;

    return r;
}

mp_uint_t blit_vfs_file_ioctl(mp_obj_t file_obj, mp_uint_t request, uintptr_t arg, int *errcode) {
    auto file = (blit_vfs_file *)MP_OBJ_TO_PTR(file_obj);

    switch (request) {
        case MP_STREAM_FLUSH:
            return 0;

        case MP_STREAM_SEEK: {
            struct mp_stream_seek_t *s = (struct mp_stream_seek_t *)arg;
            if(s->whence == SEEK_CUR)
                s->offset += file->off;
            else if(s->whence == SEEK_END)
                s->offset = api.get_file_length(file->fh) - s->offset;

            file->off = s->offset;
            return 0;
        }
        case MP_STREAM_CLOSE:
            api.close_file(file->fh);
            file->fh = nullptr;
            return 0;
        default:
            *errcode = EINVAL;
            return MP_STREAM_ERROR;
    }
}
