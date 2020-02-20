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

# We need the absolute path so that CMake will find tools correctly.
#
# On Linux, versioned LLVM tools get symlinked into /usr/bin. For example
# clang-9 is actually located at /usr/lib/llvm-9/bin/clang but it is symlinked
# as /usr/bin/clang-9. When CMake uses the /usr/bin path, that's also where it
# looks for other tools. This can lead to inconsistent versions used; such as
# clang-9 and the system default llvm-ar (which is likely a much older version).
get_filename_component(clang_abspath "${CLANG_EXECUTABLE}" REALPATH)

# These variables need to be forced otherwise CMake will overwrite them in the
# second part of the configuration phase. CMake overwrites them with the
# original, non-absolute path for some reason.
set(CMAKE_C_COMPILER ${clang_abspath} CACHE FILEPATH "" FORCE)
set(CMAKE_CXX_COMPILER ${clang_abspath} CACHE FILEPATH "" FORCE)
set(CMAKE_ASM_COMPILER ${clang_abspath} CACHE FILEPATH "" FORCE)

set(CMAKE_C_COMPILER_TARGET ${CLANG_TRIPLE})
set(CMAKE_CXX_COMPILER_TARGET ${CLANG_TRIPLE})
set(CMAKE_ASM_COMPILER_TARGET ${CLANG_TRIPLE})
