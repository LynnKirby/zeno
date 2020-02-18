# SPDX-License-Identifier: CC0-1.0
#
# guess_target() function
#
# Usage:
#     guess_target(ARCH SYS)
#     do_something_with(${ARCH} ${SYS})
#
# Determine the current target's processor and operating system.  CMake does
# this itself and exposes some properties for querying that information, however
# it makes no guarantees about the format that info is in. With this we always
# control the output.

set(_guess_target_dir ${CMAKE_CURRENT_LIST_DIR})

function(_guess_target extension kind variable)
    if(${extension} STREQUAL ".c")
        set(source "${_guess_target_dir}/guess-target.c")
    else()
        set(source "${CMAKE_BINARY_DIR}/guess-target${extension}")
        configure_file(
            "${_guess_target_dir}/guess-target.c" "${source}" COPYONLY)
    endif()

    try_compile(
        compile_success
        "${CMAKE_BINARY_DIR}"
        "${source}"
        COMPILE_DEFINITIONS "-DGUESS_TARGET_${kind}"
        OUTPUT_VARIABLE result)

    string(REGEX MATCH "cmake_${kind}=([a-zA-Z0-9_]+)" guess "${result}")
    string(REPLACE "cmake_${kind}=" "" guess "${guess}")

    # We expect the compile to fail since we use #error directives for
    # detection.
    if(${compile_success} OR ("${guess}" STREQUAL ""))
        message(
            FATAL_ERROR
            "Could not detect ${kind} using guess-target${extension}:\n"
            "${result}")
    endif()

    set(${variable}
        "${guess}"
        PARENT_SCOPE)
endfunction()

function(guess_target arch_var sys_var)
    _guess_target(.c ARCH c_arch)
    _guess_target(.c SYS c_sys)
    _guess_target(.S ARCH asm_arch)
    _guess_target(.S SYS asm_sys)

    if(NOT "${c_arch}-${c_sys}" STREQUAL "${asm_arch}-${asm_sys}")
        message(
            FATAL_ERROR
            " C and ASM compilers have different build targets:\n"
            " C: ${c_arch}-${c_sys}\n"
            " ASM: ${asm_arch}-${asm_sys}\n"
            " Most likely you are cross-compiling and did not set flags for"
            " both languages.")
    endif()

    set(${arch_var} "${c_arch}" PARENT_SCOPE)
    set(${sys_var} "${c_sys}" PARENT_SCOPE)
endfunction()
