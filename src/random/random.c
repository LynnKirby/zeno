/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * This implementation of the POSIX random() family of functions does not
 * conform to the standard but that has no effect on the observed behavior.
 *
 * - POSIX describes the internal state. This uses a completely different RNG.
 *
 * - With a maximum state size of 256, the generator is supposed to have a
 *   period greater than 2^69. This generator always has a period of 2^64.
 *   The difference is not observable: it would take over 100 years on current
 *   consumer-grade hardware to go through the 2^64 period.
 *
 * - Increasing the state should increase the period. At the lowest state size
 *   we will never finish the period so any increases of state size/period are
 *   unobservable to begin with.
 */

/* TODO: Remove once feature tests are implemented. */
#define _LIBC_POSIX_VISIBLE 1

#include "random/pcg32.h"
#include <stdint.h>
#include <stdlib.h>

_Static_assert(sizeof(int) == sizeof(uint32_t), "int must be 32 bits");

static uint64_t initial_state_buffer = PCG32_INITIAL_STATE;
static char *state                   = (char *)&initial_state_buffer;

long random(void)
{
    return pcg32_rand((uint64_t *)state) & INT32_MAX;
}

void srandom(unsigned seed)
{
    pcg32_srandom((uint64_t *)state, seed);
}

char *initstate(unsigned seed, char *new_state, size_t size)
{
    if (size < 8) return NULL;
    char *old_state = state;
    state           = new_state;
    srandom(seed);
    return old_state;
}

char *setstate(char *new_state)
{
    char *old_state = state;
    state           = new_state;
    return old_state;
}
