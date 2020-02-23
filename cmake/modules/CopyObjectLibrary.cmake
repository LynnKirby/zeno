# SPDX-License-Identifier: CC0-1.0
#
# copy_object_libraries() function
#
# Usage:
#     add_library(foo OBJECT first.c)
#     add_library(bar OBJECT second.c)
#     copy_object_library(foo bar)
#
# Copies object files created by the given object library into the target's
# LIBRARY_OUTPUT_DIRECTORY. Can provide multiple object libraries.
#
# Object libraries aren't affected by *_OUTPUT_DIRECTORY variables so we need to
# copy them over manually this way.

find_package(
    Python3
    COMPONENTS Interpreter
    REQUIRED)

set(script "${CMAKE_CURRENT_LIST_DIR}/copy_object_library.py")

function(copy_object_library name)
    foreach(target IN LISTS ARGV)
        get_target_property(outdir ${target} LIBRARY_OUTPUT_DIRECTORY)

        # We need to use an external script because the only way to get the
        # names of the object files is with the TARGET_OBJECTS generator
        # expression. That information is generator-specific and not available
        # within CMake list files.
        add_custom_target(
            ${target}_object_file_output
            COMMAND Python3::Interpreter
                    "${script}"
                    "$<TARGET_OBJECTS:${target}>"
                    "${outdir}"
            WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
            COMMAND_EXPAND_LISTS)

        add_dependencies(${target}_object_file_output ${target})
    endforeach()
endfunction()
