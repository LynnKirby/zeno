# SPDX-License-Identifier: CC0-1.0

target_sources(
    _zeno PRIVATE
    fesetenv.c
    fesetexceptflag.c
    ${_TARGET_ARCH}/__libc_fesetenv.S
    ${_TARGET_ARCH}/__libc_fesetround.S
    ${_TARGET_ARCH}/fegetenv.S
    ${_TARGET_ARCH}/fegetround.S
    ${_TARGET_ARCH}/fesetexcept.S
    ${_TARGET_ARCH}/fetestexcept.S)
