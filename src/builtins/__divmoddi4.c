/*
 * SPDX-License-Identifier: CC0-1.0
 * Compiler support routine (libgcc).
 * Calculates 64-bit quotient and remainder by signed division.
 */

#include "builtins/libgcc.h"
#include <stdbool.h>
#include <stdint.h>

int64_t __divmoddi4(int64_t num, int64_t den, int64_t *rem)
{
    bool neg_quot = false;
    bool neg_rem  = false;

    if (num < 0) {
        num      = -num;
        neg_quot = true;
        neg_rem  = true;
    }

    if (den < 0) {
        den      = -den;
        neg_quot = !neg_quot;
    }

    int64_t quot = __udivmoddi4(num, den, (uint64_t *)rem);

    if (neg_quot) {
        quot = -quot;
    }

    if (rem && neg_rem) {
        *rem = -(*rem);
    }

    return quot;
}
