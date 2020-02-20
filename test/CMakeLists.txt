# SPDX-License-Identifier: CC0-1.0

#
# List of all tests.
#

set(tests
    ctype/c_locale

    header/float
    header/inttypes
    header/limits
    header/stdarg
    header/stddef
    header/stdint
    header/stdlib
    header/stdnoreturn
    header/string

    initfini/assert_xfail
    initfini/constructor
    initfini/main_args

    random/rand

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
    string/strcspn
    string/strlen
    string/strncat
    string/strncmp
    string/strncpy
    string/strpbrk
    string/strrchr
    string/strspn
    string/strstr
    string/strtok)

# TODO: Investigate this failing test. Either bug in Clang or Wasmtime related
# to large objects used as variable arguments.
if(_TARGET_ARCH STREQUAL wasm32)
    list(REMOVE_ITEM tests header/stdarg)
endif()

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

    if(TARGET _all_copy_objlib)
        add_dependencies(${name} _all_copy_objlib)
    endif()

    set_target_properties(
        ${name} PROPERTIES EXCLUDE_FROM_ALL ${exclude_from_all})

    add_test(NAME ${name} COMMAND ${name})
endforeach()

# TODO: Extract this kind of information into test info files and automatic
# the checks.

set_property(
    TEST initfini-assert_xfail
    PROPERTY WILL_FAIL ON)

set_property(
    TEST initfini-constructor
    PROPERTY PASS_REGULAR_EXPRESSION "^ctor\nmain\ndtor\n$")
