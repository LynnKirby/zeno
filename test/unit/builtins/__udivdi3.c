#include "builtins/libgcc.h"
#include "unit_test.h"
#include <stddef.h>
#include <stdint.h>

#include "__udivmoddi4_data.inl"

TEST(__udivdi3, validates_against_data)
{
    size_t count = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < count; i++) {
        uint64_t num           = tests[i][0];
        uint64_t den           = tests[i][1];
        uint64_t expected_quot = tests[i][2];

        uint64_t quot = __udivdi3(num, den);

        ASSERT_UINT(quot, ==, expected_quot);
    }
}
