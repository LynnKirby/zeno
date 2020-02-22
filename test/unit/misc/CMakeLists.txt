# SPDX-License-Identifier: CC0-1.0

# TODO: Investigate this failing test. Either bug in Clang or Wasmtime related
# to large objects used as variable arguments.
if(NOT _TARGET_ARCH STREQUAL wasm32)
    add_unit_tests(stdarg.c)
endif()
