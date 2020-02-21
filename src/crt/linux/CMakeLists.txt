# SPDX-License-Identifier: CC0-1.0

include(CopyObjectLibrary)

add_library(crtbegin OBJECT crtbegin.c)
add_library(crtend   OBJECT crtend.c)
add_library(crti     OBJECT ${_TARGET_ARCH}/crti.S)
add_library(crtn     OBJECT ${_TARGET_ARCH}/crtn.S)
add_library(crt1     OBJECT ${_TARGET_ARCH}/crt1.S)

foreach(lib IN ITEMS crtbegin crtend crti crtn crt1)
    target_link_libraries(${lib} PRIVATE _zeno_config)
    target_compile_options(${lib} PRIVATE ${_ZENO_WARNINGS})
    copy_object_library(${lib})
endforeach()
