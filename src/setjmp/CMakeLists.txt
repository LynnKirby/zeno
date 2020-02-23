# SPDX-License-Identifier: CC0-1.0

if(NOT _TARGET_ARCH STREQUAL wasm32)
    target_sources(
        _zeno PRIVATE
        ${_TARGET_ARCH}/longjmp.S
        ${_TARGET_ARCH}/setjmp.S)
endif()
