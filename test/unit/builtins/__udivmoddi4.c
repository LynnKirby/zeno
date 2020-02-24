#include "builtins/libgcc.h"
#include "unit_test.h"
#include <stddef.h>
#include <stdint.h>

#include "__udivmoddi4_data.inl"

TEST(__udivmoddi4, validates_against_data)
{
    size_t count = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < count; i++) {
        uint64_t num           = tests[i][0];
        uint64_t den           = tests[i][1];
        uint64_t expected_quot = tests[i][2];
        uint64_t expected_rem  = tests[i][3];

        uint64_t rem;
        uint64_t quot = __udivmoddi4(num, den, &rem);

        /* Asserts because if there's a bug we'll get many, many failures.
         * Thousands of failed assertions isn't useful info. */
        ASSERT_UINT(quot, ==, expected_quot);
        ASSERT_UINT(rem, ==, expected_rem);
    }
}

TEST(__udivmoddi4, does_not_write_to_null_rem)
{
    /* Should not segfault. */
    __udivmoddi4(1, 1, NULL);
}
