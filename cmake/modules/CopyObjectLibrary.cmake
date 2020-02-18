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

set(_copy_objlib_dir ${CMAKE_CURRENT_LIST_DIR})
add_library(_all_copy_objlib INTERFACE)

function(copy_object_library name)
    foreach(target IN LISTS ARGV)
        get_target_property(outdir ${target} LIBRARY_OUTPUT_DIRECTORY)

        add_custom_target(
            _copy_objlib_${target} ALL
            COMMAND Python3::Interpreter ${_copy_objlib_dir}/copy-objlib.py
                    $<TARGET_OBJECTS:${target}> ${outdir}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMAND_EXPAND_LISTS)

        add_dependencies(_copy_objlib_${target} ${target})
        add_dependencies(_all_copy_objlib _copy_objlib_${target})
    endforeach()
endfunction()
