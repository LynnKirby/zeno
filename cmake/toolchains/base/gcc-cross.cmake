# Base definitions for cross-compiling with GCC

if(NOT DEFINED GCC_TRIPLE)
    message(FATAL_ERROR "GCC_TRIPLE not defined")
endif()

set(base ${GCC_TRIPLE}-gcc)

find_program(
    GCC_EXECUTABLE
    NAMES
        ${GCC_TRIPLE}-gcc-9
        ${GCC_TRIPLE}-gcc-8
        ${GCC_TRIPLE}-gcc-7
        ${GCC_TRIPLE}-gcc
    DOC "Path to GCC executable.")

if(GCC_EXECUTABLE STREQUAL "GCC_EXECUTABLE-NOTFOUND")
    message(FATAL_ERROR "Could not find GCC executable.")
endif()

message(STATUS "GCC_TRIPLE=${GCC_TRIPLE}")

set(CMAKE_C_COMPILER ${GCC_EXECUTABLE})
set(CMAKE_CXX_COMPILER ${GCC_EXECUTABLE})
set(CMAKE_ASM_COMPILER ${GCC_EXECUTABLE})
