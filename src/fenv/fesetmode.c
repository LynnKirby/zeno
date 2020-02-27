/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>

int fesetmode(const femode_t *modep)
{
    int mode = modep == FE_DFL_MODE ? FE_TONEAREST : *modep;
    return fesetround(mode);
}
