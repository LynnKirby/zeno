# SPDX-License-Identifier: CC0-1.0
#
# set_default_build_type() macro
#
# Usage: set_default_build_type()
#
# If we're in a git repository, assume we want Debug build by default.
# Otherwise, set the default build type to RelWithDebInfo.

macro(set_default_build_type)
    set(default_build_type "RelWithDebInfo")

    if(EXISTS "${CMAKE_SOURCE_DIR}/.git")
        set(default_build_type "Debug")
    endif()

    if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
        message(STATUS "Build type set to default of ${default_build_type}.")
        set(CMAKE_BUILD_TYPE
            "${default_build_type}"
            CACHE STRING "Choose the type of build." FORCE)
        set_property(
            CACHE
            CMAKE_BUILD_TYPE
            PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
    endif()
endmacro()
