# SPDX-License-Identifier: CC0-1.0

if(_TARGET_ARCH MATCHES "wasm")
    target_sources(
        _zeno PRIVATE
        wasm/fenv.c)
else()
    if(_TARGET_ARCH MATCHES "i386|x86_64")
        add_subdirectory(x86)
    endif()

    target_sources(
        _zeno PRIVATE
        feclearexcept.c
        fegetexceptflag.c
        fegetmode.c
        feholdexcept.c
        feraiseexcept.c
        fesetmode.c
        fesetround.c
        fetestexceptflag.c
        feupdateenv.c)
endif()
