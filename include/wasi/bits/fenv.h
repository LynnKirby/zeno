/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/fenv.h private header - WASM version
 */

#ifndef _BITS_FENV_H
#define _BITS_FENV_H

#define FE_TONEAREST  0
#define FE_ALL_EXCEPT 0

typedef char fexcept_t;
typedef char femode_t;
typedef char fenv_t;

#define FE_DFL_ENV ((const fenv_t *)-1)
#define FE_DFL_MODE ((const femode_t *)-1)

#endif
