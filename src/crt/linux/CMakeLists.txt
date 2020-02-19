# SPDX-License-Identifier: CC0-1.0

include(CopyObjectLibrary)

add_library(crtbegin OBJECT crtbegin.c)
add_library(crtend   OBJECT crtend.c)
add_library(crti     OBJECT ${_TARGET_ARCH}/crti.S)
add_library(crtn     OBJECT ${_TARGET_ARCH}/crtn.S)
add_library(crt1     OBJECT ${_TARGET_ARCH}/crt1.S)

target_link_libraries(crtbegin PRIVATE _zeno_config)
target_link_libraries(crtend   PRIVATE _zeno_config)
target_link_libraries(crti     PRIVATE _zeno_config)
target_link_libraries(crtn     PRIVATE _zeno_config)
target_link_libraries(crt1     PRIVATE _zeno_config)

target_compile_options(crtbegin PRIVATE ${_ZENO_WARNINGS})
target_compile_options(crtend   PRIVATE ${_ZENO_WARNINGS})
target_compile_options(crti     PRIVATE ${_ZENO_WARNINGS})
target_compile_options(crtn     PRIVATE ${_ZENO_WARNINGS})
target_compile_options(crt1     PRIVATE ${_ZENO_WARNINGS})

copy_object_library(crtbegin crtend crti crtn crt1)
