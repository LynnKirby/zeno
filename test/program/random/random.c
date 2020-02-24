#include "unit_test.h"
#include <stdlib.h>

TEST(random, seeded_at_program_start)
{
    long initial = random();
    srandom(1);
    EXPECT_INT(random(), ==, initial);
}

TEST(random, can_switch_states)
{
    char state0[8];
    char *result_state0 = initstate(123, state0, 8);
    long result_random0 = random();

    char state1[8];
    char *result_state1 = initstate(123, state1, 8);
    long result_random1 = random();

    EXPECT_PTR(result_state0, !=, NULL);
    EXPECT_PTR(result_state1, ==, state0);
    EXPECT_INT(result_random0, ==, result_random1);
}
