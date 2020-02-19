#include "test.h"
#include <float.h>

#ifndef FLT_ROUNDS
#error "FLT_ROUNDS not defined"
#endif

int main(void)
{
    assert_is_integer_constant(FLT_EVAL_METHOD);
    assert_is_integer_constant(FLT_HAS_SUBNORM);
    assert_is_integer_constant(DBL_HAS_SUBNORM);
    assert_is_integer_constant(LDBL_HAS_SUBNORM);
    assert_is_integer_constant(FLT_RADIX);
    assert_is_integer_constant(FLT_MANT_DIG);
    assert_is_integer_constant(DBL_MANT_DIG);
    assert_is_integer_constant(LDBL_MANT_DIG);
    assert_is_integer_constant(FLT_DECIMAL_DIG);
    assert_is_integer_constant(DBL_DECIMAL_DIG);
    assert_is_integer_constant(LDBL_DECIMAL_DIG);
    assert_is_integer_constant(DECIMAL_DIG);
    assert_is_integer_constant(FLT_DIG);
    assert_is_integer_constant(DBL_DIG);
    assert_is_integer_constant(LDBL_DIG);
    assert_is_integer_constant(FLT_MIN_EXP);
    assert_is_integer_constant(DBL_MIN_EXP);
    assert_is_integer_constant(LDBL_MIN_EXP);
    assert_is_integer_constant(FLT_MIN_10_EXP);
    assert_is_integer_constant(DBL_MIN_10_EXP);
    assert_is_integer_constant(LDBL_MIN_10_EXP);
    assert_is_integer_constant(FLT_MAX_EXP);
    assert_is_integer_constant(DBL_MAX_EXP);
    assert_is_integer_constant(LDBL_MAX_EXP);
    assert_is_integer_constant(FLT_MAX_10_EXP);
    assert_is_integer_constant(DBL_MAX_10_EXP);
    assert_is_integer_constant(LDBL_MAX_10_EXP);
    assert_is_float_constant(FLT_MAX);
    assert_is_float_constant(DBL_MAX);
    assert_is_float_constant(LDBL_MAX);
    assert_is_float_constant(FLT_NORM_MAX);
    assert_is_float_constant(DBL_NORM_MAX);
    assert_is_float_constant(LDBL_NORM_MAX);
    assert_is_float_constant(FLT_EPSILON);
    assert_is_float_constant(DBL_EPSILON);
    assert_is_float_constant(LDBL_EPSILON);
    assert_is_float_constant(FLT_MIN);
    assert_is_float_constant(DBL_MIN);
    assert_is_float_constant(LDBL_MIN);
    assert_is_float_constant(FLT_TRUE_MIN);
    assert_is_float_constant(DBL_TRUE_MIN);
    assert_is_float_constant(LDBL_TRUE_MIN);
    return 0;
}
