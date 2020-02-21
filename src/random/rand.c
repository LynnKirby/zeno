/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * This rand() and srand() implementation uses PCG XSH-RR 64/32 (aka pcg32).
 * It has better statistical performance than the common methods used in libcs.
 * The period is 2^64 and it has very good statistical qualities.
 *
 * See also:
 * - PCG website - https://www.pcg-random.org/
 * - Melissa E. O'Neill, "PCG: A Family of Simple Fast Space-Efficient
 *   Statistically Good Algorithms for Random Number Generation"
 *   https://www.pcg-random.org/pdf/hmc-cs-2014-0905.pdf
 */

#include <stdint.h>
#include <stdlib.h>

_Static_assert(sizeof(int) == sizeof(uint32_t), "int must be 32 bits");

#define MULTIPLIER 6364136223846793005ULL
#define INCREMENT  1442695040888963407ULL

static uint64_t state = 8240147227655269471;

static inline uint32_t rotr32(uint32_t value, unsigned rot)
{
    return (value >> rot) | (value << ((-rot) & 31));
}

/* Step function is a basic linear congruential generator. */
static inline void step(void)
{
    state = state * MULTIPLIER + INCREMENT;
}

/* The output function gives this generator its good statistical qualities. */
static inline uint64_t output(uint64_t value)
{
    return rotr32(((value >> 18u) ^ value) >> 27u, value >> 59u);
}

void srand(unsigned seed)
{
    state = 0;
    step();
    state += seed;
    step();
}

int rand(void)
{
    uint64_t old = state;
    step();
    return output(old) & RAND_MAX;
}
