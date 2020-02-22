#include "header_test.h"
#include <limits.h>

int main(void)
{
    integer_constant(BOOL_WIDTH);
    STATIC_ASSERT(BOOL_WIDTH > 1);

    integer_constant(CHAR_BIT);
    integer_constant(CHAR_WIDTH);
    integer_constant(SCHAR_WIDTH);
    integer_constant(UCHAR_WIDTH);
    STATIC_ASSERT(CHAR_BIT >= 8);
    STATIC_ASSERT(CHAR_WIDTH == CHAR_BIT);
    STATIC_ASSERT(SCHAR_WIDTH == CHAR_BIT);
    STATIC_ASSERT(UCHAR_WIDTH == CHAR_BIT);

    integer_constant(SHRT_WIDTH);
    integer_constant(USHRT_WIDTH);
    STATIC_ASSERT(SHRT_WIDTH >= 16);
    STATIC_ASSERT(USHRT_WIDTH == SHRT_WIDTH);
    STATIC_ASSERT(SHRT_WIDTH >= CHAR_WIDTH);

    integer_constant(INT_WIDTH);
    integer_constant(UINT_WIDTH);
    STATIC_ASSERT(INT_WIDTH >= 16);
    STATIC_ASSERT(UINT_WIDTH == INT_WIDTH);
    STATIC_ASSERT(INT_WIDTH >= SHRT_WIDTH);

    integer_constant(LONG_WIDTH);
    integer_constant(ULONG_WIDTH);
    STATIC_ASSERT(LONG_WIDTH >= 32);
    STATIC_ASSERT(ULONG_WIDTH == LONG_WIDTH);
    STATIC_ASSERT(LONG_WIDTH >= INT_WIDTH);

    integer_constant(LLONG_WIDTH);
    integer_constant(ULLONG_WIDTH);
    STATIC_ASSERT(LLONG_WIDTH >= 64);
    STATIC_ASSERT(ULLONG_WIDTH == LLONG_WIDTH);
    STATIC_ASSERT(LLONG_WIDTH >= LONG_WIDTH);

    integer_constant(MB_LEN_MAX);
    STATIC_ASSERT(MB_LEN_MAX >= 1);

    integer_constant(SCHAR_MIN);
    integer_constant(SCHAR_MAX);
    integer_constant(UCHAR_MAX);
    integer_constant(CHAR_MIN);
    integer_constant(CHAR_MAX);
    STATIC_ASSERT(UCHAR_MIN == 0);
    STATIC_ASSERT(CHAR_MIN == UCHAR_MIN || CHAR_MIN == SCHAR_MIN);
    STATIC_ASSERT(CHAR_MAX == UCHAR_MAX || CHAR_MAX == SCHAR_MAX);

    integer_constant(SHRT_MIN);
    integer_constant(SHRT_MAX);
    integer_constant(USHRT_MAX);

    integer_constant(INT_MIN);
    integer_constant(INT_MAX);
    integer_constant(UINT_MAX);

    integer_constant(LONG_MIN);
    integer_constant(LONG_MAX);
    integer_constant(ULONG_MAX);

    integer_constant(LLONG_MIN);
    integer_constant(LLONG_MAX);
    integer_constant(ULLONG_MAX);

    return 0;
}
