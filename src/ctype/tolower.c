/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int tolower(int c)
{
    if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c;
}
