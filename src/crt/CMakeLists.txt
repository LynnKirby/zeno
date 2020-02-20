# SPDX-License-Identifier: CC0-1.0

if(IS_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/${_TARGET_SYS}")
    add_subdirectory(${_TARGET_SYS})
endif()
