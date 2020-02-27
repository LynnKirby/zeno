/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>

int feholdexcept(fenv_t *envp)
{
    fegetenv(envp);
    return feclearexcept(FE_ALL_EXCEPT);
}
