# SPDX-License-Identifier: CC0-1.0

#
# List of all tests.
#

set(tests constructor)

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
# Build the tests.
#

foreach(test IN LISTS tests)
    foreach(std IN ITEMS 99 11)
        set(name ${test}_c${std})

        add_executable(${name} ${test}.c)
        target_link_libraries(${name} ${libc} _zeno_config)
        target_compile_options(${name} PRIVATE ${_ZENO_WARNINGS})
        add_dependencies(${name} _all_copy_objlib)

        set_target_properties(
            ${name}
            PROPERTIES
                C_STANDARD ${std}
                C_STANDARD_REQUIRED ON
                POSITION_INDEPENDENT_CODE OFF
                EXCLUDE_FROM_ALL ${exclude_from_all})

        add_test(NAME ${name} COMMAND ${name})
    endforeach()
endforeach()
