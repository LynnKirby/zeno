/*
 * SPDX-License-Identifier: CC0-1.0
 * Compiler support routine (libgcc).
 * Calculates 64-bit quotient.
 */

#include "builtins/libgcc.h"
#include <stddef.h>
#include <stdint.h>

uint64_t __udivdi3(uint64_t num, uint64_t den)
{
    return __udivmoddi4(num, den, NULL);
}
