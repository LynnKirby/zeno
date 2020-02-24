# SPDX-License-Identifier: CC0-1.0

find_package(
    Python3
    COMPONENTS Interpreter
    REQUIRED)

#
# Handle test build options.
#

set(_TEST_SOURCE_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})

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
# Handle unit tests. All unit tests are compiled into a single executable.
#

add_executable(test-unit unit_test.c unit_test_main.c)
add_test(NAME unit COMMAND test-unit --quiet)

target_link_libraries(test-unit ${libc} _zeno_config)
target_include_directories(test-unit PRIVATE .)
target_compile_options(test-unit PRIVATE ${_ZENO_WARNINGS})

set_target_properties(
    test-unit PROPERTIES EXCLUDE_FROM_ALL ${exclude_from_all})

function(add_unit_tests)
    foreach(file IN LISTS ARGV)
        target_sources(test-unit PRIVATE "${CMAKE_CURRENT_LIST_DIR}/${file}")
    endforeach()
endfunction()

#
# Handle full program tests. They test behavior that changes global state, uses
# the standard streams, or cannot otherwise be verified solely with assertions
# (such as testing what happens after main()).
#

function(_add_test_executable namevar file)
    # Convert a path under this test/ directory into a test name.
    # E.g. test/program/random/rand.c -> program-random-rand
    file(RELATIVE_PATH name ${_TEST_SOURCE_DIRECTORY} ${file})
    get_filename_component(dir ${name} DIRECTORY)
    get_filename_component(base ${name} NAME_WE)
    set(name "${dir}/${base}")
    string(REPLACE "/" "-" name "${name}")

    set(exe test-${name})
    add_executable(${exe} "${file}")
    target_link_libraries(${exe} ${libc} _zeno_config)
    target_include_directories(${exe} PRIVATE ${_TEST_SOURCE_DIRECTORY})
    target_compile_options(${exe} PRIVATE ${_ZENO_WARNINGS})
    set_target_properties(
        ${exe} PROPERTIES EXCLUDE_FROM_ALL ${exclude_from_all})

    set(${namevar} ${name} PARENT_SCOPE)
endfunction()

function(add_program_tests)
    foreach(file IN LISTS ARGV)
        set(file "${CMAKE_CURRENT_LIST_DIR}/${file}")
        _add_test_executable(name "${file}")

        target_sources(
            test-${name} PRIVATE "${_TEST_SOURCE_DIRECTORY}/unit_test.c")

        # Use a shorter relative path for the source file since it will
        # show up in error messages.
        file(RELATIVE_PATH file_relpath "${PROJECT_SOURCE_DIR}" "${file}")

        # Use the crosscompiling emulator (if defined) as the program argument
        # for check_program.py. The script will forward all the arguments to
        # the emulator.
        add_test(
            NAME ${name}
            COMMAND "${Python3_EXECUTABLE}"
                    "${_TEST_SOURCE_DIRECTORY}/check_program.py"
                    "${file_relpath}"
                    "${CMAKE_CROSSCOMPILING_EMULATOR}"
                    "$<TARGET_FILE:test-${name}>"
                    --quiet
            WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
            COMMAND_EXPAND_LISTS)
        set_tests_properties(${name} PROPERTIES CROSSCOMPILING_EMULATOR "")
    endforeach()
endfunction()

#
# Handle header tests. They only have static assertions and so aren't added
# as CTest tests. We only compile them.
#

function(add_header_tests)
    foreach(file IN LISTS ARGV)
        set(file "${CMAKE_CURRENT_LIST_DIR}/${file}")
        _add_test_executable(_ignored "${file}")
    endforeach()
endfunction()

#
# Let subdirectories define their tests using the add_*_tests() functions.
#

add_subdirectory(header)
add_subdirectory(program)
add_subdirectory(unit)
