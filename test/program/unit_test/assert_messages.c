#include "unit_test.h"
#include <stddef.h>

// RETURN: 1

TEST(unit_test, basic_asserts)
{
    // CHECK: 1 == 2
    EXPECT(1 == 2);
}

TEST(unit_test, signed_messages)
{
    int one = 1;
    int two = 2;

    // CHECK: one == -two (1 == -2)
    EXPECT_INT(one, ==, -two);

    // CHECK: -one != -one (-1 != -1)
    EXPECT_INT(-one, !=, -one);

    // CHECK: -one > -one (-1 > -1)
    EXPECT_INT(-one, >, -one);

    // CHECK: -one > two (-1 > 2)
    EXPECT_INT(-one, >, two);

    // CHECK: -two < -two (-2 < -2)
    EXPECT_INT(-two, <, -two);

    // CHECK: two <= -one (2 <= -1)
    EXPECT_INT(two, <=, -one);
}

TEST(unit_test, unsigned_messages)
{
    unsigned one = 1;
    unsigned two = 2;

    // CHECK: one == two (1 == 2)
    EXPECT_UINT(one, ==, two);

    // CHECK: one != one (1 != 1)
    EXPECT_UINT(one, !=, one);

    // CHECK: one > two (1 > 2)
    EXPECT_UINT(one, >, two);
}

TEST(unit_test, char_asserts)
{
    char a = 'a';
    char b = 'b';
    char space = ' ';
    char tab = '\t';
    char null = '\0';
    char control = 1;

    // CHECK: a == b ('a' == 'b')
    EXPECT_CHAR(a, ==, b);

    // CHECK: a == space ('a' == ' ')
    EXPECT_CHAR(a, ==, space);

    // CHECK: a == tab ('a' == '\t')
    EXPECT_CHAR(a, ==, tab);

    // CHECK: a == null ('a' == '\0')
    EXPECT_CHAR(a, ==, null);

    // CHECK: a == control ('a' == 1)
    EXPECT_CHAR(a, ==, control);
}

TEST(unit_test, ptr_asserts)
{
    char var;
    void *null = NULL;

    // CHECK: null == &var (NULL ==
    EXPECT_PTR(null, ==, &var);

    // CHECK: NULL == &var (NULL ==
    EXPECT_PTR(NULL, ==, &var);
}
