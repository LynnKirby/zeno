#include "unit_test.h"
#include <ctype.h>

TEST(ctype, c_locale)
{
    EXPECT_INT(isalnum('b'), !=, 0);
    EXPECT_INT(isalnum(' '), ==, 0);

    EXPECT_INT(isalpha('a'), !=, 0);
    EXPECT_INT(isalpha('?'), ==, 0);

    EXPECT_INT(isblank(' '), !=, 0);
    EXPECT_INT(isblank('\n'), ==, 0);

    EXPECT_INT(iscntrl('\b'), !=, 0);
    EXPECT_INT(iscntrl('a'), ==, 0);

    EXPECT_INT(isdigit('0'), !=, 0);
    EXPECT_INT(isdigit('-'), ==, 0);

    EXPECT_INT(isgraph(':'), !=, 0);
    EXPECT_INT(isgraph('\t'), ==, 0);

    EXPECT_INT(islower('m'), !=, 0);
    EXPECT_INT(islower('M'), ==, 0);

    EXPECT_INT(isprint(' '), !=, 0);
    EXPECT_INT(isprint('\b'), ==, 0);

    EXPECT_INT(ispunct(','), !=, 0);
    EXPECT_INT(ispunct(' '), ==, 0);

    EXPECT_INT(isspace('\r'), !=, 0);
    EXPECT_INT(isspace('\0'), ==, 0);

    EXPECT_INT(isupper('M'), !=, 0);
    EXPECT_INT(isupper('m'), ==, 0);

    EXPECT_INT(isxdigit('F'), !=, 0);
    EXPECT_INT(isxdigit('x'), ==, 0);

    EXPECT_CHAR(tolower('X'), ==, 'x');
    EXPECT_CHAR(tolower('+'), ==, '+');
    EXPECT_CHAR(toupper('x'), ==, 'X');
    EXPECT_CHAR(toupper('+'), ==, '+');
}
