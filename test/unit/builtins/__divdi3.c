#include "unit_test.h"

#include "builtins/libgcc.h"

TEST(__divdi3, basic)
{
    EXPECT_INT(__divdi3(0, 1), ==, 0);
    EXPECT_INT(__divdi3(0, -1), ==, 0);
    EXPECT_INT(__divdi3(2, 1), ==, 2);
    EXPECT_INT(__divdi3(2, -1), ==, -2);
    EXPECT_INT(__divdi3(-2, 1), ==, -2);
    EXPECT_INT(__divdi3(-2, -1), ==, 2);

    EXPECT_INT(__divdi3(0x8000000000000000LL, 1), ==, 0x8000000000000000LL);
    EXPECT_INT(__divdi3(0x8000000000000000LL, -1), ==, 0x8000000000000000LL);
    EXPECT_INT(__divdi3(0x8000000000000000LL, -2), ==, 0x4000000000000000LL);
    EXPECT_INT(__divdi3(0x8000000000000000LL, 2), ==, 0xC000000000000000LL);
}
