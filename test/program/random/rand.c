#include "unit_test.h"
#include "unit_test_main.c"
#include <stdlib.h>

TEST(rand, seeded_at_program_start)
{
    int initial = rand();
    srand(1);
    EXPECT_INT(rand(), ==, initial);
}
