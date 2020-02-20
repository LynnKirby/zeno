# Cross-compile toolchain for wasm32-wasi with Clang
# Requires wasmtime for emulation to work: https://wasmtime.dev/

find_program(
    WASMTIME
    NAMES wasmtime
    # User installer puts it here.
    HINTS $ENV{HOME}/.wasmtime/bin)

if(WASMTIME STREQUAL WASMTIME-NOTFOUND)
    message(FATAL_ERROR "Could not find wasmtime for wasm32-wasi emulation.")
endif()

set(CMAKE_CROSSCOMPILING_EMULATOR ${WASMTIME})

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR wasm32)
set(CLANG_TRIPLE wasm32-wasi)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
include(${CMAKE_CURRENT_LIST_DIR}/base/clang.cmake)
