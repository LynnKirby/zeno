/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>

int feclearexcept(int excepts)
{
    excepts &= FE_ALL_EXCEPT;

    if (excepts != 0)
    {
        fexcept_t zero = 0;
        fesetexceptflag(&zero, excepts);
    }

    return 0;
}
