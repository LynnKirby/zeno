# SPDX-License-Identifier: CC0-1.0

target_sources(
    _zeno
    PRIVATE
    __libc_start_main.c
    __libc_csu_init.c
    __libc_csu_fini.c
    _Exit.c)
