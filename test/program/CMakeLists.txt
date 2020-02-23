# SPDX-License-Identifier: CC0-1.0

add_subdirectory(initfini)
add_subdirectory(random)
add_subdirectory(stdio)
add_subdirectory(stdlib)
add_subdirectory(unit_test)

if(NOT _TARGET_ARCH STREQUAL wasm32)
    add_subdirectory(setjmp)
endif()
