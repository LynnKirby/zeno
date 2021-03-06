#include "unit_test.h"
#include <string.h>

TEST(memmove, no_overlap_and_src_before_dest)
{
    char buffer[] = { 0, 1, 2, 3, 4, 5 };
    char *src     = buffer;
    char *dest    = buffer + 3;

    void *result = memmove(dest, src, 3);

    EXPECT_PTR(result, ==, dest);

    EXPECT_INT(buffer[0], ==, 0);
    EXPECT_INT(buffer[1], ==, 1);
    EXPECT_INT(buffer[2], ==, 2);
    EXPECT_INT(buffer[3], ==, 0);
    EXPECT_INT(buffer[4], ==, 1);
    EXPECT_INT(buffer[5], ==, 2);
}

TEST(memmove, no_overlap_and_src_after_dest)
{
    char buffer[] = { 0, 1, 2, 3, 4, 5 };
    char *src     = buffer + 3;
    char *dest    = buffer;

    void *result = memmove(dest, src, 3);

    EXPECT_PTR(result, ==, dest);

    EXPECT_INT(buffer[0], ==, 3);
    EXPECT_INT(buffer[1], ==, 4);
    EXPECT_INT(buffer[2], ==, 5);
    EXPECT_INT(buffer[3], ==, 3);
    EXPECT_INT(buffer[4], ==, 4);
    EXPECT_INT(buffer[5], ==, 5);
}

TEST(memmove, overlap_and_src_before_dest)
{
    char buffer[] = { 0, 1, 2, 3, 4, 5 };
    char *src     = buffer;
    char *dest    = buffer + 2;

    void *result = memmove(dest, src, 4);

    EXPECT_PTR(result, ==, dest);

    EXPECT_INT(buffer[0], ==, 0);
    EXPECT_INT(buffer[1], ==, 1);
    EXPECT_INT(buffer[2], ==, 0);
    EXPECT_INT(buffer[3], ==, 1);
    EXPECT_INT(buffer[4], ==, 2);
    EXPECT_INT(buffer[5], ==, 3);
}

TEST(memmove, overlap_and_src_after_dest)
{
    char buffer[] = { 0, 1, 2, 3, 4, 5 };
    char *src     = buffer + 2;
    char *dest    = buffer;

    void *result = memmove(dest, src, 4);

    EXPECT_PTR(result, ==, dest);

    EXPECT_INT(buffer[0], ==, 2);
    EXPECT_INT(buffer[1], ==, 3);
    EXPECT_INT(buffer[2], ==, 4);
    EXPECT_INT(buffer[3], ==, 5);
    EXPECT_INT(buffer[4], ==, 4);
    EXPECT_INT(buffer[5], ==, 5);
}

TEST(memmove, src_is_dest)
{
    char buffer[] = { 0, 1, 2, 3, 4, 5 };

    void *result = memmove(buffer, buffer, 4);

    EXPECT_PTR(result, ==, buffer);

    EXPECT_INT(buffer[0], ==, 0);
    EXPECT_INT(buffer[1], ==, 1);
    EXPECT_INT(buffer[2], ==, 2);
    EXPECT_INT(buffer[3], ==, 3);
    EXPECT_INT(buffer[4], ==, 4);
    EXPECT_INT(buffer[5], ==, 5);
}
