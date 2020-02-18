# SPDX-License-Identifier: CC0-1.0
#
# ensure_out_of_source_build() macro
#
# Usage: ensure_out_of_source_build()
#
# Makes sure we're not building directly in the project root since that will
# create a mess of files. Unfortunately we can't catch this before CMake's
# initial configuration so we'll still be left with a few files in the project
# root.

macro(ensure_out_of_source_build)
    if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
        message(
            FATAL_ERROR
            " You must build ${PROJECT_NAME} out-of-source."
            " For example in ${CMAKE_SOURCE_DIR}/build.")
    endif()
endmacro()
