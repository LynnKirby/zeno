/* SPDX-License-Identifier: CC0-1.0 */

#include <stdlib.h>

div_t div(int numer, int denom)
{
    return (div_t){ .quot = numer / denom, .rem = numer % denom };
}
