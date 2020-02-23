# SPDX-License-Identifier: CC0-1.0

include(CopyObjectLibrary)

add_library(
    crt
    OBJECT
    crtbegin.c
    crtend.c
    ${_TARGET_ARCH}/crti.S
    ${_TARGET_ARCH}/crtn.S
    ${_TARGET_ARCH}/crt1.S)

target_link_libraries(crt PRIVATE _zeno_config)
target_compile_options(crt PRIVATE ${_ZENO_WARNINGS})
copy_object_library(crt)
