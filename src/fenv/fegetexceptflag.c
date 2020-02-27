/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>

int fegetexceptflag(fexcept_t *flagp, int excepts)
{
    *flagp = fetestexcept(excepts);
    return 0;
}
