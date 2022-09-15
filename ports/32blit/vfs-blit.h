#pragma once

#include "mod32blit.h"

#ifdef __cplusplus
extern "C" {
#endif

mp_obj_t blit_vfs_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);

mp_obj_t blit_vfs_mount(mp_obj_t self, mp_obj_t readonly, mp_obj_t mkfs);
mp_obj_t blit_vfs_umount(mp_obj_t self);
mp_obj_t blit_vfs_open(mp_obj_t self, mp_obj_t path_obj, mp_obj_t mode_obj);

extern const mp_obj_type_t blit_vfs_type;

// file
mp_obj_t blit_vfs_file_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);

mp_uint_t blit_vfs_file_read(mp_obj_t file_obj, void *buf, mp_uint_t size, int *errcode);
mp_uint_t blit_vfs_file_write(mp_obj_t file_obj, const void *buf, mp_uint_t size, int *errcode);
mp_uint_t blit_vfs_file_ioctl(mp_obj_t file_obj, mp_uint_t request, uintptr_t arg, int *errcode);

extern const mp_obj_type_t blit_vfs_textio_type;

#ifdef __cplusplus
}
#endif
