#include "unit_test.h"
#include <string.h>

TEST(strcpy, works)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strcpy(dest, src);

    EXPECT_PTR(result, ==, dest);

    EXPECT_CHAR(buffer[0], ==, 1);
    EXPECT_CHAR(buffer[1], ==, 'f');
    EXPECT_CHAR(buffer[2], ==, 'o');
    EXPECT_CHAR(buffer[3], ==, 'o');
    EXPECT_CHAR(buffer[4], ==, '\0');
    EXPECT_CHAR(buffer[5], ==, 1);
}
