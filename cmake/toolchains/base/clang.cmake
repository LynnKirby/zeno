# Base definitions for cross-compiling with Clang

if(NOT DEFINED CLANG_TRIPLE)
    message(FATAL_ERROR "CLANG_TRIPLE not defined")
endif()

find_program(
    CLANG_EXECUTABLE
    NAMES
        clang-9
        clang
    DOC "Path to Clang executable.")

if(CLANG_EXECUTABLE STREQUAL "CLANG_EXECUTABLE-NOTFOUND")
    message(FATAL_ERROR "Could not find clang executable.")
endif()

message(STATUS "CLANG_TRIPLE=${CLANG_TRIPLE}")

set(CMAKE_C_COMPILER ${CLANG_EXECUTABLE})
set(CMAKE_C_COMPILER_TARGET ${CLANG_TRIPLE})

set(CMAKE_CXX_COMPILER ${CLANG_EXECUTABLE})
set(CMAKE_CXX_COMPILER_TARGET ${CLANG_TRIPLE})

set(CMAKE_ASM_COMPILER ${CLANG_EXECUTABLE})
set(CMAKE_ASM_COMPILER_TARGET ${CLANG_TRIPLE})
