/*
 * SPDX-License-Identifier: CC0-1.0
 * Compiler support routine (libgcc).
 * Calculates 64-bit quotient and remainder.
 */

#include "builtins/libgcc.h"
#include <stdint.h>

uint64_t __udivmoddi4(uint64_t N, uint64_t D, uint64_t *rem)
{
    /* The easy conditions. */
    if (D == 0) {
        return 1 / D;
    }

    if (N == D) {
        if (rem) {
            *rem = 0;
        }
        return 1;
    }

    if (N < D) {
        if (rem) {
            *rem = N;
        }
        return 0;
    }

    /* Use 32-bit division if possible. */
    if (((N >> 32) | (D >> 32)) == 0) {
        if (rem) {
            /* TODO: verify this optimizes as DIV on i386, or do it by hand */
            *rem = (uint32_t)N % (uint32_t)D;
            return (uint32_t)N / (uint32_t)D;
        }
        return (uint32_t)N / (uint32_t)D;
    }

    /* Do long division. */
    uint64_t Q = 0;
    uint64_t R = 0;

    for (int i = 63; i >= 0; i--) {
        uint64_t bit = UINT64_C(1) << i;
        R <<= 1;

        /* set bits: R[0] = N[i] */
        if ((N & bit) == 0) {
            R &= ~1;
        } else {
            R |= 1;
        }

        if (R >= D) {
            R -= D;
            Q |= bit;
        }
    }

    if (rem) {
        *rem = R;
    }

    return Q;
}
