# Base definitions for compiling with the Intel C/C++ Compiler

find_program(
    ICC_EXECUTABLE
    NAMES icc
    DOC "Path to icc executable.")

if(ICC_EXECUTABLE STREQUAL "ICC_EXECUTABLE-NOTFOUND")
    message(FATAL_ERROR "Could not find icc executable.")
endif()

set(CMAKE_C_COMPILER ${ICC_EXECUTABLE})
set(CMAKE_CXX_COMPILER ${ICC_EXECUTABLE})
set(CMAKE_ASM_COMPILER ${ICC_EXECUTABLE})
