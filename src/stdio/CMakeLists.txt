# SPDX-License-Identifier: CC0-1.0

target_sources(
    _zeno PRIVATE
    fputs.c
    puts.c
    std_streams.c)

add_subdirectory(${_TARGET_SYS})
