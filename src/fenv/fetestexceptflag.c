/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>

int fetestexceptflag(const fexcept_t* flagp, int excepts)
{
    return *flagp & excepts & FE_ALL_EXCEPT;
}
