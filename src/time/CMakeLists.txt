# SPDX-License-Identifier: CC0-1.0

add_subdirectory(${_TARGET_SYS})

target_sources(
    _zeno PRIVATE
    difftime.c
    mktime.c
    time.c
    timespec_get.c)
