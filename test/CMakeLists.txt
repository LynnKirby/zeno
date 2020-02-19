# SPDX-License-Identifier: CC0-1.0

#
# List of all tests.
#

set(tests
    header/float
    header/limits
    header/stdarg
    header/stddef
    header/stdint
    header/stdlib
    header/stdnoreturn
    header/string

    initfini/constructor

    string/memccpy
    string/memchr
    string/memcmp
    string/memcpy
    string/memmove
    string/memset
    string/strcat
    string/strchr
    string/strcmp
    string/strcpy
    string/strlen
    string/strncat
    string/strncmp
    string/strncpy)

#
# Handle test build options.
#

if(ZENO_BUILD_TESTS)
    set(exclude_from_all OFF)
else()
    set(exclude_from_all ON)
endif()

if(ZENO_LINK_TESTS_STATIC)
    set(libc zeno-static)
else()
    set(libc zeno-shared)
endif()

#
# Warning suppression.
#

list(APPEND _ZENO_WARNINGS -Wno-unused-variable)

#
# Build the tests.
#

foreach(test IN LISTS tests)
    set(name ${test})
    string(REPLACE "/" "-" name ${name})

    add_executable(${name} ${test}.c)
    target_link_libraries(${name} ${libc} _zeno_config)
    target_compile_options(${name} PRIVATE ${_ZENO_WARNINGS})
    target_include_directories(${name} PRIVATE .)
    add_dependencies(${name} _all_copy_objlib)

    set_target_properties(
        ${name} PROPERTIES EXCLUDE_FROM_ALL ${exclude_from_all})

    add_test(NAME ${name} COMMAND ${name})
endforeach()
