#include "header_test.h"
#include <float.h>

#ifndef FLT_ROUNDS
#error "FLT_ROUNDS not defined"
#endif

int main(void)
{
    integer_constant(FLT_EVAL_METHOD);
    integer_constant(FLT_HAS_SUBNORM);
    integer_constant(DBL_HAS_SUBNORM);
    integer_constant(LDBL_HAS_SUBNORM);
    integer_constant(FLT_RADIX);
    integer_constant(FLT_MANT_DIG);
    integer_constant(DBL_MANT_DIG);
    integer_constant(LDBL_MANT_DIG);
    integer_constant(FLT_DECIMAL_DIG);
    integer_constant(DBL_DECIMAL_DIG);
    integer_constant(LDBL_DECIMAL_DIG);
    integer_constant(DECIMAL_DIG);
    integer_constant(FLT_DIG);
    integer_constant(DBL_DIG);
    integer_constant(LDBL_DIG);
    integer_constant(FLT_MIN_EXP);
    integer_constant(DBL_MIN_EXP);
    integer_constant(LDBL_MIN_EXP);
    integer_constant(FLT_MIN_10_EXP);
    integer_constant(DBL_MIN_10_EXP);
    integer_constant(LDBL_MIN_10_EXP);
    integer_constant(FLT_MAX_EXP);
    integer_constant(DBL_MAX_EXP);
    integer_constant(LDBL_MAX_EXP);
    integer_constant(FLT_MAX_10_EXP);
    integer_constant(DBL_MAX_10_EXP);
    integer_constant(LDBL_MAX_10_EXP);
    float_constant(FLT_MAX);
    float_constant(DBL_MAX);
    float_constant(LDBL_MAX);
    float_constant(FLT_NORM_MAX);
    float_constant(DBL_NORM_MAX);
    float_constant(LDBL_NORM_MAX);
    float_constant(FLT_EPSILON);
    float_constant(DBL_EPSILON);
    float_constant(LDBL_EPSILON);
    float_constant(FLT_MIN);
    float_constant(DBL_MIN);
    float_constant(LDBL_MIN);
    float_constant(FLT_TRUE_MIN);
    float_constant(DBL_TRUE_MIN);
    float_constant(LDBL_TRUE_MIN);
    return 0;
}
