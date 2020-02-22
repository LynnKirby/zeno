#include "unit_test.h"
#include <stdlib.h>

TEST(rand, seeded_at_program_start)
{
    int initial = rand();
    srand(1);
    EXPECT(rand() == initial);
}
