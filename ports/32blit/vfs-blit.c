#include "py/stream.h"

#include "vfs-blit.h"

STATIC MP_DEFINE_CONST_FUN_OBJ_3(blit_vfs_mount_obj, blit_vfs_mount);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_vfs_umount_obj, blit_vfs_umount);
STATIC MP_DEFINE_CONST_FUN_OBJ_3(blit_vfs_open_obj, blit_vfs_open);

STATIC MP_DEFINE_CONST_FUN_OBJ_1(blit_vfs_getcwd_obj, blit_vfs_getcwd);
STATIC MP_DEFINE_CONST_FUN_OBJ_2(blit_vfs_stat_obj, blit_vfs_stat);

STATIC const mp_rom_map_elem_t blit_vfs_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_mount), MP_ROM_PTR(&blit_vfs_mount_obj) },
    { MP_ROM_QSTR(MP_QSTR_umount), MP_ROM_PTR(&blit_vfs_umount_obj) },
    { MP_ROM_QSTR(MP_QSTR_open), MP_ROM_PTR(&blit_vfs_open_obj) },

    { MP_ROM_QSTR(MP_QSTR_getcwd), MP_ROM_PTR(&blit_vfs_getcwd_obj) },
    // TODO: mkdir, rename, remove, rmdir
    { MP_ROM_QSTR(MP_QSTR_stat), MP_ROM_PTR(&blit_vfs_stat_obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_vfs_locals_dict, blit_vfs_locals_dict_table);

const mp_obj_type_t blit_vfs_type = {
    { &mp_type_type },
    .name = MP_QSTR_VfsFont,
    .make_new = blit_vfs_make_new,
    .locals_dict = (mp_obj_dict_t*)&blit_vfs_locals_dict,
};

// file
STATIC mp_obj_t blit_vfs_file___exit___(size_t n_args, const mp_obj_t *args) {
    return mp_stream_close(args[0]);
}

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(blit_vfs_file___exit___obj, 4, 4, blit_vfs_file___exit___);

STATIC const mp_rom_map_elem_t blit_vfs_file_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_read), MP_ROM_PTR(&mp_stream_read_obj) },
    { MP_ROM_QSTR(MP_QSTR_readinto), MP_ROM_PTR(&mp_stream_readinto_obj) },
    { MP_ROM_QSTR(MP_QSTR_readline), MP_ROM_PTR(&mp_stream_unbuffered_readline_obj) },
    { MP_ROM_QSTR(MP_QSTR_readlines), MP_ROM_PTR(&mp_stream_unbuffered_readlines_obj) },
    { MP_ROM_QSTR(MP_QSTR_write), MP_ROM_PTR(&mp_stream_write_obj) },
    { MP_ROM_QSTR(MP_QSTR_seek), MP_ROM_PTR(&mp_stream_seek_obj) },
    { MP_ROM_QSTR(MP_QSTR_tell), MP_ROM_PTR(&mp_stream_tell_obj) },
    { MP_ROM_QSTR(MP_QSTR_flush), MP_ROM_PTR(&mp_stream_flush_obj) },
    { MP_ROM_QSTR(MP_QSTR_close), MP_ROM_PTR(&mp_stream_close_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&mp_identity_obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__), MP_ROM_PTR(&blit_vfs_file___exit___obj) },
};

STATIC MP_DEFINE_CONST_DICT(blit_vfs_file_locals_dict, blit_vfs_file_locals_dict_table);

// TODO: FileIO?

STATIC const mp_stream_p_t blit_vfs_textio_stream_p = {
    .read = blit_vfs_file_read,
    .write = blit_vfs_file_write,
    .ioctl = blit_vfs_file_ioctl,
    .is_text = true,
};

const mp_obj_type_t blit_vfs_textio_type = {
    { &mp_type_type },
    .name = MP_QSTR_TextIOWrapper,
    .make_new = blit_vfs_file_make_new,
    .getiter = mp_identity_getiter,
    .iternext = mp_stream_unbuffered_iter,
    .protocol = &blit_vfs_textio_stream_p,
    .locals_dict = (mp_obj_dict_t *)&blit_vfs_file_locals_dict,
};
