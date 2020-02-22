# Cross-compile toolchain for wasm32-wasi with Clang
# Requires wasmtime for emulation to work: https://wasmtime.dev/

if(DEFINED ENV{WASMTIME_HOME})
    list(APPEND hints "$ENV{WASMTIME_HOME}/bin")
endif()

if(DEFINED ENV{HOME})
    list(APPEND hints "$ENV{HOME}/.wasmtime/bin")
endif()

find_program(
    WASMTIME
    NAMES wasmtime
    HINTS ${hints})

if(WASMTIME STREQUAL WASMTIME-NOTFOUND)
    message(FATAL_ERROR "Could not find wasmtime for wasm32-wasi emulation.")
endif()

message(STATUS "Found wasmtime: ${WASMTIME}")

find_package(
    Python3
    COMPONENTS Interpreter
    REQUIRED)

get_filename_component(
    runner_script
    ${CMAKE_CURRENT_LIST_DIR}/../../test/run_wasmtime.py
    ABSOLUTE)

unset(emulator)
list(APPEND emulator ${Python3_EXECUTABLE})
list(APPEND emulator ${runner_script})
list(APPEND emulator ${WASMTIME})
set(CMAKE_CROSSCOMPILING_EMULATOR ${emulator})

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR wasm32)
set(CLANG_TRIPLE wasm32-wasi)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
include(${CMAKE_CURRENT_LIST_DIR}/base/clang.cmake)
