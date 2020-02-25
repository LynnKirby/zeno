/*
 * SPDX-License-Identifier: CC0-1.0
 * Compiler support routine (libgcc).
 * Calculates 64-bit quotient by signed division.
 */

#include "builtins/libgcc.h"
#include <stddef.h>
#include <stdint.h>

int64_t __divdi3(int64_t num, int64_t den)
{
    return __divmoddi4(num, den, NULL);
}
