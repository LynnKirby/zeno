/*
 * SPDX-License-Identifier CC0-1.0
 *
 * WebAssembly only supports round-to-nearest and has no observable exception
 * status flags so these functions do mostly nothing. We still read and write
 * from pointers so that the behavior between fenv implementations is
 * consistent.
 */

#include <fenv.h>

int feclearexcept(int excepts)
{
    (void)excepts;
    return 0;
}

int fegetexceptflag(fexcept_t *flagp, int excepts)
{
    (void)excepts;
    *flagp = 0;
    return 0;
}

int feraiseexcept(int excepts)
{
    (void)excepts;
    return 0;
}

int fesetexcept(int excepts)
{
    (void)excepts;
    return 0;
}

int fesetexceptflag(const fexcept_t *flagp, int excepts)
{
    (void)excepts;
    volatile int x = *flagp;
    (void)x;
    return 0;
}

int fetestexceptflag(const fexcept_t *flagp, int excepts)
{
    (void)excepts;
    volatile int x = *flagp;
    (void)x;
    return 0;
}

int fetestexcept(int excepts)
{
    (void)excepts;
    return 0;
}

int fegetmode(femode_t *modep)
{
    *modep = 0;
    return 0;
}

int fegetround(void)
{
    return 0;
}

int fesetmode(const femode_t *modep)
{
    volatile int x = modep == FE_DFL_MODE ? 0 : *modep;
    (void)x;
    return 0;
}

int fesetround(int round)
{
    return round == 0 ? 0 : -1;
}

int fegetenv(fenv_t *envp)
{
    *envp = 0;
    return 0;
}

int feholdexcept(fenv_t *envp)
{
    *envp = 0;
    return 0;
}

int fesetenv(const fenv_t *envp)
{
    volatile int x = envp == FE_DFL_ENV ? 0 : *envp;
    (void)x;
    return 0;
}

int feupdateenv(const fenv_t *envp)
{
    volatile int x = envp == FE_DFL_ENV ? 0 : *envp;
    (void)x;
    return 0;
}
