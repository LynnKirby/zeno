#include "test.h"
#include <limits.h>

int main(void)
{
    assert_is_integer_constant(BOOL_WIDTH);
    assert(BOOL_WIDTH > 1);

    assert_is_integer_constant(CHAR_BIT);
    assert_is_integer_constant(CHAR_WIDTH);
    assert_is_integer_constant(SCHAR_WIDTH);
    assert_is_integer_constant(UCHAR_WIDTH);
    assert(CHAR_BIT >= 8);
    assert(CHAR_WIDTH == CHAR_BIT);
    assert(SCHAR_WIDTH == CHAR_BIT);
    assert(UCHAR_WIDTH == CHAR_BIT);

    assert_is_integer_constant(SHRT_WIDTH);
    assert_is_integer_constant(USHRT_WIDTH);
    assert(SHRT_WIDTH >= 16);
    assert(USHRT_WIDTH == SHRT_WIDTH);
    assert(SHRT_WIDTH >= CHAR_WIDTH);

    assert_is_integer_constant(INT_WIDTH);
    assert_is_integer_constant(UINT_WIDTH);
    assert(INT_WIDTH >= 16);
    assert(UINT_WIDTH == INT_WIDTH);
    assert(INT_WIDTH >= SHRT_WIDTH);

    assert_is_integer_constant(LONG_WIDTH);
    assert_is_integer_constant(ULONG_WIDTH);
    assert(LONG_WIDTH >= 32);
    assert(ULONG_WIDTH == LONG_WIDTH);
    assert(LONG_WIDTH >= INT_WIDTH);

    assert_is_integer_constant(LLONG_WIDTH);
    assert_is_integer_constant(ULLONG_WIDTH);
    assert(LLONG_WIDTH >= 64);
    assert(ULLONG_WIDTH == LLONG_WIDTH);
    assert(LLONG_WIDTH >= LONG_WIDTH);

    assert_is_integer_constant(MB_LEN_MAX);
    assert(MB_LEN_MAX >= 1);

    assert_is_integer_constant(SCHAR_MIN);
    assert_is_integer_constant(SCHAR_MAX);
    assert_is_integer_constant(UCHAR_MAX);
    assert_is_integer_constant(CHAR_MIN);
    assert_is_integer_constant(CHAR_MAX);
    assert(UCHAR_MIN == 0);
    assert(CHAR_MIN == UCHAR_MIN || CHAR_MIN == SCHAR_MIN);
    assert(CHAR_MAX == UCHAR_MAX || CHAR_MAX == SCHAR_MAX);

    assert_is_integer_constant(SHRT_MIN);
    assert_is_integer_constant(SHRT_MAX);
    assert_is_integer_constant(USHRT_MAX);

    assert_is_integer_constant(INT_MIN);
    assert_is_integer_constant(INT_MAX);
    assert_is_integer_constant(UINT_MAX);

    assert_is_integer_constant(LONG_MIN);
    assert_is_integer_constant(LONG_MAX);
    assert_is_integer_constant(ULONG_MAX);

    assert_is_integer_constant(LLONG_MIN);
    assert_is_integer_constant(LLONG_MAX);
    assert_is_integer_constant(ULLONG_MAX);

    return 0;
}
