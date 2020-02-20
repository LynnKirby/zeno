/* SPDX-License-Identifier: CC0-1.0 */

#include <stdlib.h>

lldiv_t lldiv(long long numer, long long denom)
{
    return (lldiv_t){ .quot = numer / denom, .rem = numer % denom };
}
