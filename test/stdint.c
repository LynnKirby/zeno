#include "test.h"

/* These tokens are directly used by helper macros in stdint.h. Since they
 * aren't reserved tokens, we need to ensure that the header still works if the
 * user decides to define them. */
#define uint 0
#define INT 0
#define UINT 0
#define _t 0

#include <stdint.h>

int main(void)
{
    assert_is_integer_constant(__STDC_VERSION_STDINT_H__);

    assert_is_type(int8_t);
    assert_is_type(int16_t);
    assert_is_type(int32_t);
    assert_is_type(int64_t);

    assert_is_type(uint8_t);
    assert_is_type(uint16_t);
    assert_is_type(uint32_t);
    assert_is_type(uint64_t);

    assert_is_type(int_least8_t);
    assert_is_type(int_least16_t);
    assert_is_type(int_least32_t);
    assert_is_type(int_least64_t);

    assert_is_type(uint_least8_t);
    assert_is_type(uint_least16_t);
    assert_is_type(uint_least32_t);
    assert_is_type(uint_least64_t);

    assert_is_type(int_fast8_t);
    assert_is_type(int_fast16_t);
    assert_is_type(int_fast32_t);
    assert_is_type(int_fast64_t);

    assert_is_type(uint_fast8_t);
    assert_is_type(uint_fast16_t);
    assert_is_type(uint_fast32_t);
    assert_is_type(uint_fast64_t);

    assert_is_type(intptr_t);
    assert_is_type(uintptr_t);
    assert_is_type(intmax_t);
    assert_is_type(uintmax_t);

    assert_is_integer_constant(INT8_MIN);
    assert_is_integer_constant(INT8_MAX);
    assert_is_integer_constant(UINT8_MAX);

    assert_is_integer_constant(INT16_MIN);
    assert_is_integer_constant(INT16_MAX);
    assert_is_integer_constant(UINT16_MAX);

    assert_is_integer_constant(INT32_MIN);
    assert_is_integer_constant(INT32_MAX);
    assert_is_integer_constant(UINT32_MAX);

    assert_is_integer_constant(INT64_MIN);
    assert_is_integer_constant(INT64_MAX);
    assert_is_integer_constant(UINT64_MAX);

    assert_is_integer_constant(INT_LEAST8_MIN);
    assert_is_integer_constant(INT_LEAST8_MAX);
    assert_is_integer_constant(UINT_LEAST8_MAX);

    assert_is_integer_constant(INT_LEAST16_MIN);
    assert_is_integer_constant(INT_LEAST16_MAX);
    assert_is_integer_constant(UINT_LEAST16_MAX);

    assert_is_integer_constant(INT_LEAST32_MIN);
    assert_is_integer_constant(INT_LEAST32_MAX);
    assert_is_integer_constant(UINT_LEAST32_MAX);

    assert_is_integer_constant(INT_LEAST64_MIN);
    assert_is_integer_constant(INT_LEAST64_MAX);
    assert_is_integer_constant(UINT_LEAST64_MAX);

    assert_is_integer_constant(INT_FAST8_MIN);
    assert_is_integer_constant(INT_FAST8_MAX);
    assert_is_integer_constant(UINT_FAST8_MAX);

    assert_is_integer_constant(INT_FAST16_MIN);
    assert_is_integer_constant(INT_FAST16_MAX);
    assert_is_integer_constant(UINT_FAST16_MAX);

    assert_is_integer_constant(INT_FAST32_MIN);
    assert_is_integer_constant(INT_FAST32_MAX);
    assert_is_integer_constant(UINT_FAST32_MAX);

    assert_is_integer_constant(INT_FAST64_MIN);
    assert_is_integer_constant(INT_FAST64_MAX);
    assert_is_integer_constant(UINT_FAST64_MAX);

    assert_is_integer_constant(INTPTR_MIN);
    assert_is_integer_constant(INTPTR_MAX);
    assert_is_integer_constant(UINTPTR_MAX);

    assert_is_integer_constant(INTMAX_MIN);
    assert_is_integer_constant(INTMAX_MAX);
    assert_is_integer_constant(UINTMAX_MAX);

    assert_is_integer_constant(PTRDIFF_MIN);
    assert_is_integer_constant(PTRDIFF_MAX);

    assert_is_integer_constant(SIG_ATOMIC_MIN);
    assert_is_integer_constant(SIG_ATOMIC_MAX);

    assert_is_integer_constant(SIZE_MAX);

    assert_is_integer_constant(WCHAR_MIN);
    assert_is_integer_constant(WCHAR_MAX);

    assert_is_integer_constant(WINT_MIN);
    assert_is_integer_constant(WINT_MAX);

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
