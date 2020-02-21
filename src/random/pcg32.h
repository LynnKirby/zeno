/* SPDX-License-Identifier: CC0-1.0 */

#ifndef RANDOM_PCG32_H
#define RANDOM_PCG32_H

#include <stdint.h>

#define PCG32_MULTIPLIER UINT64_C(6364136223846793005)
#define PCG32_INCREMENT  UINT64_C(1442695040888963407)

/* Precomputed state after pcg32_srandom(1). */
#define PCG32_INITIAL_STATE UINT64_C(8240147227655269471)

void __libc_pcg32_srandom(uint64_t *state, uint32_t seed);
uint32_t __libc_pcg32_rand(uint64_t *state);

#define pcg32_srandom(state, seed) __libc_pcg32_srandom(state, seed)
#define pcg32_rand(state)          __libc_pcg32_rand(state)

#endif
