/* SPDX-License-Identifier: CC0-1.0 */

#include <fenv.h>

int fegetmode(femode_t *modep)
{
    *modep = fegetround();
    return 0;
}
