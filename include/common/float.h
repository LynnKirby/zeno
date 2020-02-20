/*
 * SPDX-License-Identifier: CC0-1.0
 * float.h standard C header
 */

#ifndef _FLOAT_H
#define _FLOAT_H

#include <bits/config.h>

/* TODO: Update when fenv.h functions are available. */
#define FLT_ROUNDS (-1)

#define FLT_RADIX   2
#define DECIMAL_DIG LDBL_DECIMAL_DIG

#ifdef __FLT_EVAL_METHOD__
#define FLT_EVAL_METHOD __FLT_EVAL_METHOD__
#else
#define FLT_EVAL_METHOD (-1)
#endif

/* float == IEC 60559 binary32 */
#define FLT_MANT_DIG    24
#define FLT_DIG         6
#define FLT_DECIMAL_DIG 9
#define FLT_MIN_EXP     (-125)
#define FLT_MAX_EXP     128
#define FLT_MIN_10_EXP  (-37)
#define FLT_MAX_10_EXP  38
#define FLT_EPSILON     1.19209290e-07F
#define FLT_MIN         1.17549435e-38F
#define FLT_TRUE_MIN    1.40129846e-45F
#define FLT_MAX         3.40282347e+38F
#define FLT_NORM_MAX    FLT_MAX
#define FLT_HAS_SUBNORM 1

/* double == IEC 60559 binary64 */
#define DBL_MANT_DIG    53
#define DBL_DIG         15
#define DBL_DECIMAL_DIG 17
#define DBL_MIN_EXP     (-1021)
#define DBL_MAX_EXP     1024
#define DBL_MIN_10_EXP  (-307)
#define DBL_MAX_10_EXP  308
#define DBL_EPSILON     2.2204460492503131e-16
#define DBL_MIN         2.2250738585072014e-308
#define DBL_TRUE_MIN    4.9406564584124654e-324
#define DBL_MAX         1.7976931348623157e+308
#define DBL_NORM_MAX    DBL_MAX
#define DBL_HAS_SUBNORM 1

#if _LIBC_CONFIG_LDBL_FORMAT_BINARY64
/* long double == IEC 60559 binary64 */
#define LDBL_MANT_DIG    53
#define LDBL_DIG         15
#define LDBL_DECIMAL_DIG 17
#define LDBL_MIN_EXP     (-1021)
#define LDBL_MAX_EXP     1024
#define LDBL_MIN_10_EXP  (-307)
#define LDBL_MAX_10_EXP  308
#define LDBL_EPSILON     2.2204460492503131e-16
#define LDBL_MIN         2.2250738585072014e-308
#define LDBL_TRUE_MIN    4.9406564584124654e-324
#define LDBL_MAX         1.7976931348623157e+308
#define LDBL_NORM_MAX    LDBL_MAX
#define LDBL_HAS_SUBNORM 1
#elif _LIBC_CONFIG_LDBL_FORMAT_BINARY128
/* long double == IEC 60559 binary128 */
#define LDBL_MANT_DIG    113
#define LDBL_DIG         33
#define LDBL_DECIMAL_DIG 36
#define LDBL_MIN_EXP     (-16381)
#define LDBL_MAX_EXP     16384
#define LDBL_MIN_10_EXP  (-4931)
#define LDBL_MAX_10_EXP  4932
#define LDBL_EPSILON     1.92592994438723585305597794258492732e-34L
#define LDBL_MIN         3.36210314311209350626267781732175260e-4932L
#define LDBL_TRUE_MIN    6.47517511943802511092443895822764655e-4966L
#define LDBL_MAX         1.18973149535723176508575932662800702e+4932L
#define LDBL_NORM_MAX    LDBL_MAX
#define LDBL_HAS_SUBNORM 1
#elif _LIBC_CONFIG_LDBL_FORMAT_INTEL80
/* long double == Intel 80-bit extended precision format */
#define LDBL_MANT_DIG    64
#define LDBL_DIG         18
#define LDBL_DECIMAL_DIG 21
#define LDBL_MIN_EXP     (-16381)
#define LDBL_MAX_EXP     16384
#define LDBL_MIN_10_EXP  (-4931)
#define LDBL_MAX_10_EXP  4932
#define LDBL_EPSILON     1.08420217248550443401e-19L
#define LDBL_MIN         3.36210314311209350626e-4932L
#define LDBL_TRUE_MIN    3.64519953188247460253e-4951L
#define LDBL_MAX         1.18973149535723176502e+4932L
#define LDBL_NORM_MAX    LDBL_MAX
#define LDBL_HAS_SUBNORM 1
#endif

#endif
