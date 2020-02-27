/*
 * SPDX-License-Identifier: CC0-1.0
 * fenv.h standard C header
 */

#ifndef _FENV_H
#define _FENV_H

#include <bits/fenv.h>

#define __STDC_VERSION_FENV_H__ 202001L

/*
 * Floating-point exceptions.
 */

int feclearexcept(int);
int fegetexceptflag(fexcept_t *, int);
int feraiseexcept(int);
int fesetexcept(int);
int fesetexceptflag(const fexcept_t *, int);
int fetestexceptflag(const fexcept_t *, int);
int fetestexcept(int);

/*
 * Rounding and other control modes.
 */

int fegetmode(femode_t *);
int fegetround(void);
int fesetmode(const femode_t *);
int fesetround(int);

/*
 * Environment.
 */

int fegetenv(fenv_t *);
int feholdexcept(fenv_t *);
int fesetenv(const fenv_t *);
int feupdateenv(const fenv_t *);

#endif
