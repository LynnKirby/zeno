# SPDX-License-Identifier: CC0-1.0

#
# List of all tests.
#

set(tests
    unit/ctype/c_locale

    header/float
    header/inttypes
    header/limits
    header/stdarg
    header/stddef
    header/stdint
    header/stdlib
    header/stdnoreturn
    header/string
    header/time

    program/initfini/assert_xfail
    program/initfini/atexit
    program/initfini/constructor
    program/initfini/main_args

    unit/random/rand_r
    program/random/rand
    program/random/random

    program/stdlib/getenv

    unit/string/memccpy
    unit/string/memchr
    unit/string/memcmp
    unit/string/memcpy
    unit/string/memmove
    unit/string/memset
    unit/string/strcat
    unit/string/strchr
    unit/string/strcmp
    unit/string/strcpy
    unit/string/strcspn
    unit/string/strlen
    unit/string/strncat
    unit/string/strncmp
    unit/string/strncpy
    unit/string/strpbrk
    unit/string/strrchr
    unit/string/strspn
    unit/string/strstr
    unit/string/strtok

    unit/time/clock_gettime
    unit/time/clock)

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
    TEST program-initfini-assert_xfail
    PROPERTY WILL_FAIL ON)

foreach(n RANGE 32)
    string(APPEND atexit_test_result "${n}-")
endforeach()

set_property(
    TEST program-initfini-atexit
    PROPERTY PASS_REGULAR_EXPRESSION ${atexit_test_result})

set_property(
    TEST program-initfini-constructor
    PROPERTY PASS_REGULAR_EXPRESSION "^ctor\nmain\ndtor\n$")

set_property(
    TEST program-stdlib-getenv
    PROPERTY ENVIRONMENT "TEST_GETENV_VAR=123456")
