#include "unit_test.h"
#include <string.h>

TEST(strcat, works)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3 };

    char *result = strcat(dest, "bar");

    EXPECT_PTR(result, ==, dest);
    EXPECT_CHAR(dest[0], ==, 'f');
    EXPECT_CHAR(dest[1], ==, 'o');
    EXPECT_CHAR(dest[2], ==, 'o');
    EXPECT_CHAR(dest[3], ==, 'b');
    EXPECT_CHAR(dest[4], ==, 'a');
    EXPECT_CHAR(dest[5], ==, 'r');
    EXPECT_CHAR(dest[6], ==, '\0');
}
