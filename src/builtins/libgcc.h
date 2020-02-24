/* SPDX-License-Identifier: CC0-1.0 */

#ifndef BUILTINS_LIBGCC_H
#define BUILTINS_LIBGCC_H

#include <stdint.h>

uint64_t __udivdi3(uint64_t num, uint64_t den);
uint64_t __umoddi3(uint64_t num, uint64_t den);
uint64_t __udivmoddi4(uint64_t num, uint64_t den, uint64_t *rem);

#endif
