/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * This is PCG XSH-RR 64/32 (aka pcg32). It has 32-bit output, 64-bit state, and
 * a period of 2^64. The statistical performance is better than all of the
 * commonly used RNGs in libcs.
 *
 * See also:
 * - PCG website - https://www.pcg-random.org/
 * - Melissa E. O'Neill, "PCG: A Family of Simple Fast Space-Efficient
 *   Statistically Good Algorithms for Random Number Generation"
 *   https://www.pcg-random.org/pdf/hmc-cs-2014-0905.pdf
 */

#include "random/pcg32.h"
#include <stdint.h>
#include <stdlib.h>

static inline uint32_t rotr32(uint32_t value, unsigned rot)
{
    return (value >> rot) | (value << ((-rot) & 31));
}

/* Step function is a basic linear congruential generator. */
static inline void step(uint64_t *state)
{
    *state = *state * PCG32_MULTIPLIER + PCG32_INCREMENT;
}

/* The output function gives this generator its good statistical qualities. */
static inline uint64_t output(uint64_t value)
{
    return rotr32(((value >> 18u) ^ value) >> 27u, value >> 59u);
}

void __libc_pcg32_srandom(uint64_t *state, uint32_t seed)
{
    *state = 0;
    step(state);
    *state += seed;
    step(state);
}

uint32_t __libc_pcg32_rand(uint64_t *state)
{
    uint64_t old = *state;
    step(state);
    return output(old);
}
