#include "unit_test.h"
#include <stdlib.h>

TEST(rand_r, is_deterministic)
{
    unsigned state  = 123;
    long result0    = rand_r(&state);
    state           = 123;
    long result1    = rand_r(&state);
    unsigned state2 = 123;
    long result2    = rand_r(&state2);

    EXPECT_INT(result0, ==, result1);
    EXPECT_INT(result1, ==, result2);
}
