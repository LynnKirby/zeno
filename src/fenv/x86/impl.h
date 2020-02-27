/* SPDX-License-Identifier: CC0-1.0 */

#ifndef FENV_X86_H
#define FENV_X86_H

#include "fenv/impl.h"
#include <fenv.h>
#include <stdint.h>

/* Shift femode_t left by this to make it work with MXCSR. */
#define MXCSR_ROUNDING_SHIFT 3

/* Shift fexcept_t left by this to make it the MXCSR exception mask. */
#define MXCSR_EXCEPT_MASK_SHIFT 7

/* Mask for x87 control register and femode_t to extract rounding modes */
#define ROUNDING_MASK 0xC00

/* x87 control register flags for precision. */
#define X87_DOUBLE_PRECISION   (0x2 << 8)
#define X87_EXTENDED_PRECISION (0x3 << 8)

void __libc_fesetenv(const fenv_t *envp);

#endif
