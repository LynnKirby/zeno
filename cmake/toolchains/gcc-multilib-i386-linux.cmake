# Cross-compile toolchain for i386-linux with GCC x86 multilib

find_program(
    GCC_EXECUTABLE
    NAMES
        gcc-9
        gcc-8
        gcc-7
        gcc
    DOC "Path to GCC executable.")

if(GCC_EXECUTABLE STREQUAL "GCC_EXECUTABLE-NOTFOUND")
    message(FATAL_ERROR "Could not find GCC executable.")
endif()

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR i386)

set(CMAKE_C_COMPILER ${GCC_EXECUTABLE})
set(CMAKE_CXX_COMPILER ${GCC_EXECUTABLE})
set(CMAKE_ASM_COMPILER ${GCC_EXECUTABLE})

string(APPEND CMAKE_C_FLAGS " -m32")
string(APPEND CMAKE_CXX_FLAGS " -m32")
string(APPEND CMAKE_ASM_FLAGS " -m32")
