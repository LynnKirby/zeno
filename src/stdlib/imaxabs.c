/* SPDX-License-Identifier: CC0-1.0 */

#include <inttypes.h>

imaxdiv_t imaxdiv(intmax_t numer, intmax_t denom)
{
    return (imaxdiv_t){ .quot = numer / denom, .rem = numer % denom };
}
