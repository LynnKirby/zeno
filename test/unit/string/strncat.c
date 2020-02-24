#include "unit_test.h"
#include <string.h>

TEST(strncat, given_exact_length_of_src)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

    char *result = strncat(dest, "bar", 3);

    EXPECT_PTR(result, ==, dest);
    EXPECT_CHAR(dest[0], ==, 'f');
    EXPECT_CHAR(dest[1], ==, 'o');
    EXPECT_CHAR(dest[2], ==, 'o');
    EXPECT_CHAR(dest[3], ==, 'b');
    EXPECT_CHAR(dest[4], ==, 'a');
    EXPECT_CHAR(dest[5], ==, 'r');
    EXPECT_CHAR(dest[6], ==, '\0');
    EXPECT_CHAR(dest[7], ==, 4);
}

TEST(strncat, given_length_less_than_src)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

    char *result = strncat(dest, "bar", 2);

    EXPECT_PTR(result, ==, dest);
    EXPECT_CHAR(dest[0], ==, 'f');
    EXPECT_CHAR(dest[1], ==, 'o');
    EXPECT_CHAR(dest[2], ==, 'o');
    EXPECT_CHAR(dest[3], ==, 'b');
    EXPECT_CHAR(dest[4], ==, 'a');
    EXPECT_CHAR(dest[5], ==, '\0');
    EXPECT_CHAR(dest[6], ==, 3);
    EXPECT_CHAR(dest[7], ==, 4);
}

TEST(strncat, given_length_greater_than_src)
{
    char dest[] = { 'f', 'o', 'o', '\0', 1, 2, 3, 4 };

    char *result = strncat(dest, "bar", 100);

    EXPECT_PTR(result, ==, dest);
    EXPECT_CHAR(dest[0], ==, 'f');
    EXPECT_CHAR(dest[1], ==, 'o');
    EXPECT_CHAR(dest[2], ==, 'o');
    EXPECT_CHAR(dest[3], ==, 'b');
    EXPECT_CHAR(dest[4], ==, 'a');
    EXPECT_CHAR(dest[5], ==, 'r');
    EXPECT_CHAR(dest[6], ==, '\0');
    EXPECT_CHAR(dest[7], ==, 4);
}
