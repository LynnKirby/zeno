/* SPDX-License-Identifier: CC0-1.0 */

#include "random/pcg32.h"
#include <stdint.h>
#include <stdlib.h>

_Static_assert(sizeof(int) == sizeof(uint32_t), "int must be 32 bits");

static uint64_t state = PCG32_INITIAL_STATE;

int rand(void)
{
    return pcg32_rand(&state) & RAND_MAX;
}

void srand(unsigned seed)
{
    pcg32_srandom(&state, seed);
}
