/* SPDX-License-Identifier: CC0-1.0 */

#include <stdlib.h>

ldiv_t ldiv(long numer, long denom)
{
    return (ldiv_t){ .quot = numer / denom, .rem = numer % denom };
}
