#include <time.h>
#include "unit_test.h"

TEST(clock, can_get_time)
{
    EXPECT_INT(clock(), !=, 0);
    EXPECT_INT(clock(), !=, -1);
    EXPECT_INT(clock(), >, 0);
}
