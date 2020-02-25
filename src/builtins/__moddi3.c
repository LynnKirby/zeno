/*
 * SPDX-License-Identifier: CC0-1.0
 * Compiler support routine (libgcc).
 * Calculates 64-bit remainder by signed division.
 */

#include "builtins/libgcc.h"
#include <stdint.h>

int64_t __moddi3(int64_t num, int64_t den)
{
    int64_t rem;
    __divmoddi4(num, den, &rem);
    return rem;
}
