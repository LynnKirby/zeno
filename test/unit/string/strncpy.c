#include "unit_test.h"
#include <string.h>

TEST(strncpy, given_exact_length_of_src)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strncpy(dest, src, 4);

    EXPECT_PTR(result, ==, dest);

    EXPECT_CHAR(buffer[0], ==, 1);
    EXPECT_CHAR(buffer[1], ==, 'f');
    EXPECT_CHAR(buffer[2], ==, 'o');
    EXPECT_CHAR(buffer[3], ==, 'o');
    EXPECT_CHAR(buffer[4], ==, '\0');
    EXPECT_CHAR(buffer[5], ==, 1);
}

TEST(strncpy, given_length_less_than_src)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strncpy(dest, src, 3);

    EXPECT_PTR(result, ==, dest);

    EXPECT_CHAR(buffer[0], ==, 1);
    EXPECT_CHAR(buffer[1], ==, 'f');
    EXPECT_CHAR(buffer[2], ==, 'o');
    EXPECT_CHAR(buffer[3], ==, 'o');
    EXPECT_CHAR(buffer[4], ==, 1);
    EXPECT_CHAR(buffer[5], ==, 1);
}

TEST(strncpy, given_length_greater_than_src)
{
    const char *src = "foo";
    char buffer[]   = { 1, 1, 1, 1, 1, 1, 1, 1 };
    char *dest      = buffer + 1;

    char *result = strncpy(dest, src, 6);

    EXPECT_PTR(result, ==, dest);

    EXPECT_CHAR(buffer[0], ==, 1);
    EXPECT_CHAR(buffer[1], ==, 'f');
    EXPECT_CHAR(buffer[2], ==, 'o');
    EXPECT_CHAR(buffer[3], ==, 'o');
    EXPECT_CHAR(buffer[4], ==, '\0');
    EXPECT_CHAR(buffer[5], ==, '\0');
    EXPECT_CHAR(buffer[6], ==, '\0');
    EXPECT_CHAR(buffer[7], ==, 1);
}
