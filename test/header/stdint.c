#include "header_test.h"
#include <stdint.h>

int main(void)
{
    integer_constant(__STDC_VERSION_STDINT_H__);

    /* Types. */

    type(int8_t);
    type(int16_t);
    type(int32_t);
    type(int64_t);

    type(uint8_t);
    type(uint16_t);
    type(uint32_t);
    type(uint64_t);

    type(int_least8_t);
    type(int_least16_t);
    type(int_least32_t);
    type(int_least64_t);

    type(uint_least8_t);
    type(uint_least16_t);
    type(uint_least32_t);
    type(uint_least64_t);

    type(int_fast8_t);
    type(int_fast16_t);
    type(int_fast32_t);
    type(int_fast64_t);

    type(uint_fast8_t);
    type(uint_fast16_t);
    type(uint_fast32_t);
    type(uint_fast64_t);

    type(intptr_t);
    type(uintptr_t);
    type(intmax_t);
    type(uintmax_t);

    /* Widths. */

    integer_constant(INT8_WIDTH);
    integer_constant(UINT8_WIDTH);
    STATIC_ASSERT(INT8_WIDTH == UINT8_WIDTH);

    integer_constant(INT16_WIDTH);
    integer_constant(UINT16_WIDTH);
    STATIC_ASSERT(INT16_WIDTH == UINT16_WIDTH);

    integer_constant(INT32_WIDTH);
    integer_constant(UINT32_WIDTH);
    STATIC_ASSERT(INT32_WIDTH == UINT32_WIDTH);

    integer_constant(INT64_WIDTH);
    integer_constant(UINT64_WIDTH);
    STATIC_ASSERT(INT64_WIDTH == UINT64_WIDTH);

    integer_constant(INTMAX_WIDTH);
    integer_constant(UINTMAX_WIDTH);
    STATIC_ASSERT(INTMAX_WIDTH == UINTMAX_WIDTH);

    integer_constant(PTRDIFF_WIDTH);
    STATIC_ASSERT(PTRDIFF_WIDTH >= 17);

    integer_constant(SIG_ATOMIC_WIDTH);
    STATIC_ASSERT(SIG_ATOMIC_WIDTH >= 8);

    integer_constant(SIZE_WIDTH);
    STATIC_ASSERT(SIZE_WIDTH >= 16);

    integer_constant(WCHAR_WIDTH);
    STATIC_ASSERT(WCHAR_WIDTH >= 8);

    integer_constant(WINT_WIDTH);
    STATIC_ASSERT(WINT_WIDTH >= 8);

    /* Maximal and minimal values. */

    integer_constant(INT8_MIN);
    integer_constant(INT8_MAX);
    integer_constant(UINT8_MAX);

    integer_constant(INT16_MIN);
    integer_constant(INT16_MAX);
    integer_constant(UINT16_MAX);

    integer_constant(INT32_MIN);
    integer_constant(INT32_MAX);
    integer_constant(UINT32_MAX);

    integer_constant(INT64_MIN);
    integer_constant(INT64_MAX);
    integer_constant(UINT64_MAX);

    integer_constant(INT_LEAST8_MIN);
    integer_constant(INT_LEAST8_MAX);
    integer_constant(UINT_LEAST8_MAX);

    integer_constant(INT_LEAST16_MIN);
    integer_constant(INT_LEAST16_MAX);
    integer_constant(UINT_LEAST16_MAX);

    integer_constant(INT_LEAST32_MIN);
    integer_constant(INT_LEAST32_MAX);
    integer_constant(UINT_LEAST32_MAX);

    integer_constant(INT_LEAST64_MIN);
    integer_constant(INT_LEAST64_MAX);
    integer_constant(UINT_LEAST64_MAX);

    integer_constant(INT_FAST8_MIN);
    integer_constant(INT_FAST8_MAX);
    integer_constant(UINT_FAST8_MAX);

    integer_constant(INT_FAST16_MIN);
    integer_constant(INT_FAST16_MAX);
    integer_constant(UINT_FAST16_MAX);

    integer_constant(INT_FAST32_MIN);
    integer_constant(INT_FAST32_MAX);
    integer_constant(UINT_FAST32_MAX);

    integer_constant(INT_FAST64_MIN);
    integer_constant(INT_FAST64_MAX);
    integer_constant(UINT_FAST64_MAX);

    integer_constant(INTPTR_MIN);
    integer_constant(INTPTR_MAX);
    integer_constant(UINTPTR_MAX);

    integer_constant(INTMAX_MIN);
    integer_constant(INTMAX_MAX);
    integer_constant(UINTMAX_MAX);

    integer_constant(PTRDIFF_MIN);
    integer_constant(PTRDIFF_MAX);

    integer_constant(SIG_ATOMIC_MIN);
    integer_constant(SIG_ATOMIC_MAX);

    integer_constant(SIZE_MAX);

    integer_constant(WCHAR_MIN);
    integer_constant(WCHAR_MAX);

    integer_constant(WINT_MIN);
    integer_constant(WINT_MAX);

    /* Macros for integer constants. */

    int_least8_t l8     = INT8_C(0);
    uint_least8_t ul8   = UINT8_C(0);
    int_least16_t l16   = INT16_C(0);
    uint_least16_t ul16 = UINT16_C(0);
    int_least32_t l32   = INT32_C(0);
    uint_least32_t ul32 = UINT32_C(0);
    int_least64_t l64   = INT64_C(0);
    uint_least64_t ul64 = UINT64_C(0);
    intmax_t max        = INTMAX_C(0);
    uintmax_t umax      = UINTMAX_C(0);

    return 0;
}
