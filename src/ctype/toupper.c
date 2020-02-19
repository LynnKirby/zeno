/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int toupper(int c)
{
    if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
    return c;
}
