#include <time.h>
#include "unit_test.h"

TEST(clock, can_get_time)
{
    EXPECT(clock() != 0);
    EXPECT(clock() != -1);
    EXPECT(clock() > 0);
}
