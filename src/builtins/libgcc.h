/* SPDX-License-Identifier: CC0-1.0 */

#ifndef BUILTINS_LIBGCC_H
#define BUILTINS_LIBGCC_H

#include <stdint.h>

int64_t __divdi3(int64_t num, int64_t den);
int64_t __moddi3(int64_t num, int64_t den);
int64_t __divmoddi4(int64_t num, int64_t den, int64_t *rem);

uint64_t __udivdi3(uint64_t num, uint64_t den);
uint64_t __umoddi3(uint64_t num, uint64_t den);
uint64_t __udivmoddi4(uint64_t num, uint64_t den, uint64_t *rem);

#endif
