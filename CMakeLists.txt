# SPDX-License-Identifier: CC0-1.0

#
# Basic configuration.
#

cmake_minimum_required(VERSION 3.16)
project(Zeno C ASM)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

include(EnsureOutOfSourceBuild)
include(GuessTarget)
include(SetDefaultBuildType)

# Do this as soon as possible.
ensure_out_of_source_build()

# What are we building for?
guess_target(_TARGET_ARCH _TARGET_SYS)
message(STATUS "Target detected as ${_TARGET_ARCH}-${_TARGET_SYS}")

# Organize our compile artifacts.
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#
# Build options.
#

# Gives a sensible default to CMAKE_BUILD_TYPE if it wasn't set.
set_default_build_type()

# Output types.
set(ZENO_INCLUDE_STATIC ON CACHE BOOL "Build the static C library.")
set(ZENO_INCLUDE_SHARED OFF CACHE BOOL "Build the shared C library.")

# Diagnostics.
set(ZENO_ENABLE_WARNINGS ON CACHE BOOL "Enable warnings.")
set(ZENO_ENABLE_WERROR OFF CACHE BOOL "Fail the build on compiler warnings.")

# Tests.
set(ZENO_BUILD_TESTS ON CACHE BOOL "Build tests by default.")
set(ZENO_INCLUDE_TESTS ON CACHE BOOL "Allow building tests.")
set(ZENO_LINK_TESTS_STATIC ON CACHE BOOL "Link tests to static libc.")

#
# Compile and link configuration. We use a target-based approach for most
# compile options. Diagnostics are controlled with the _ZENO_WARNINGS list
# instead because some targets need to remove flags or add them in specific
# positions, which can't be done with targets.
#

set(public_includes
    include/generic)

if(_TARGET_ARCH MATCHES "i386|x86_64")
    list(APPEND public_includes
        "include/${_TARGET_SYS}/x86-generic"
        "include/${_TARGET_SYS}/x86-${_TARGET_ARCH}")
else()
    list(APPEND public_includes
        "include/${_TARGET_SYS}/${_TARGET_ARCH}")
endif()

add_library(_zeno_config INTERFACE)
target_include_directories(_zeno_config INTERFACE ${public_includes} src)
target_compile_options(_zeno_config INTERFACE -nostdinc -ffreestanding)
target_link_options(_zeno_config INTERFACE -nostdlib)
target_compile_features(_zeno_config INTERFACE c_std_11)

if(ZENO_ENABLE_WARNINGS)
    list(APPEND _ZENO_WARNINGS -Wall -Wextra -pedantic)
endif()

if(ZENO_ENABLE_WERROR)
    list(APPEND _ZENO_WARNINGS -Werror)
endif()

#
# Update CMAKE_C_LINK_EXECUTABLE so that the test executables get built with
# our CRT object files.
#

if(_TARGET_SYS STREQUAL linux)
    string(
        CONCAT
        startfiles
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/crti.o "
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/crtbegin.o "
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/crt1.o")

    string(
        CONCAT
        endfiles
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/crtend.o "
        "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/crtn.o")

    string(
        REPLACE
        "<OBJECTS>"
        "${startfiles} <OBJECTS> ${endfiles}"
        CMAKE_C_LINK_EXECUTABLE
        "${CMAKE_C_LINK_EXECUTABLE}")
endif()

#
# The main libraries.
#

# The object library collects and compiles all the sources. Subdirectories add
# their sources with target_sources().
add_library(_zeno OBJECT)
target_include_directories(_zeno PUBLIC ${public_includes})
target_link_libraries(_zeno PRIVATE _zeno_config)
target_compile_options(_zeno PRIVATE ${_ZENO_WARNINGS})

if(ZENO_INCLUDE_SHARED)
    add_library(zeno-shared SHARED $<TARGET_OBJECTS:_zeno>)
    set_target_properties(zeno-shared PROPERTIES OUTPUT_NAME c)
endif()

if(ZENO_INCLUDE_STATIC)
    add_library(zeno-static STATIC $<TARGET_OBJECTS:_zeno>)
    set_target_properties(zeno-static PROPERTIES OUTPUT_NAME c)
endif()

#
# Add source directories.
#

add_subdirectory(src)

if(ZENO_INCLUDE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

#
# Disable PIC and shared libraries on Linux. We don't have a linker and code
# isn't set up for it so everything breaks when we try to use it.
#

if(_TARGET_SYS STREQUAL linux)
    if(ZENO_INCLUDE_SHARED)
        message(FATAL_ERROR "ZENO_INCLUDE_SHARED=ON not supported on Linux")
    endif()

    if(NOT ZENO_LINK_TESTS_STATIC)
        message(FATAL_ERROR "ZENO_LINK_TESTS_STATIC=OFF not supported on Linux")
    endif()

    get_directory_property(all_targets BUILDSYSTEM_TARGETS)

    foreach(target IN LISTS all_targets)
        get_target_property(target_type ${target} TYPE)

        # Only apply to *_LIBRARY or EXECUTABLE targets
        if(target_type MATCHES "((STATIC|SHARED|OBJECT)_LIBRARY)|(EXECUTABLE)")
            target_compile_options(${target} PRIVATE -fno-pie)
            target_link_libraries(${target} PRIVATE -no-pie)
        endif()
    endforeach()
endif()
