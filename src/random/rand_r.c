/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * This uses PCG RXS-M-XS 32/32 (aka pcg32si). It has 32-bit output, 32-bit
 * state, and a period of 2^32. rand_r() has notoriously bad performance due to
 * the API but this one passes SmallCrush and fails PractRand at 16GB. musl
 * rand_r() is the best existing libc version I could find; it also passes
 * SmallCrush (none of the others did) and fails PractRand at 256MB.
 *
 * See also:
 * - PCG website - https://www.pcg-random.org/
 * - Melissa E. O'Neill, "PCG: A Family of Simple Fast Space-Efficient
 *   Statistically Good Algorithms for Random Number Generation"
 *   https://www.pcg-random.org/pdf/hmc-cs-2014-0905.pdf
 */

/* TODO: Remove once feature tests are implemented. */
#define _LIBC_POSIX_VISIBLE 1

#include <stdint.h>
#include <stdlib.h>

_Static_assert(sizeof(int) == sizeof(uint32_t), "int must be 32 bits");

#define MULTIPLIER UINT32_C(747796405)
#define INCREMENT  UINT32_C(2891336453)

int rand_r(unsigned *state)
{
    uint32_t old = *state;

    /* Step. */
    *state = *state * MULTIPLIER + INCREMENT;

    /* Output. */
    uint32_t word = ((old >> ((old >> 28U) + 4U)) ^ old) * 277803737U;
    return ((word >> 22U) ^ word) & RAND_MAX;
}
