#include "unit_test.h"

#include "builtins/libgcc.h"

TEST(__moddi3, basic)
{
    EXPECT_INT(__moddi3(0, 1), ==, 0);
    EXPECT_INT(__moddi3(0, -1), ==, 0);
    EXPECT_INT(__moddi3(5, 3), ==, 2);
    EXPECT_INT(__moddi3(5, -3), ==, 2);
    EXPECT_INT(__moddi3(-5, 3), ==, -2);
    EXPECT_INT(__moddi3(-5, -3), ==, -2);

    EXPECT_INT(__moddi3(0x8000000000000000LL, 1), ==, 0);
    EXPECT_INT(__moddi3(0x8000000000000000LL, -1), ==, 0);
    EXPECT_INT(__moddi3(0x8000000000000000LL, 2), ==, 0);
    EXPECT_INT(__moddi3(0x8000000000000000LL, -2), ==, 0);
    EXPECT_INT(__moddi3(0x8000000000000000LL, 3), ==, -2);
    EXPECT_INT(__moddi3(0x8000000000000000LL, -3), ==, -2);
}
