/*
 * SPDX-License-Identifier: CC0-1.0
 * Compiler support routine (libgcc).
 * Calculates 64-bit remainder.
 */

#include "builtins/libgcc.h"
#include <stdint.h>

uint64_t __umoddi3(uint64_t num, uint64_t den)
{
    uint64_t rem;
    __udivmoddi4(num, den, &rem);
    return rem;
}
