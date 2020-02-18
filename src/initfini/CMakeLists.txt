# SPDX-License-Identifier: CC0-1.0

add_subdirectory(${_TARGET_SYS})

target_sources(
    _zeno PRIVATE
    assert.c
    atexit.c
    exit.c)
