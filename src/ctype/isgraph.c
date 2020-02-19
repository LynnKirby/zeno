/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int isgraph(int c)
{
    return c >= 0x21 && c <= 0x7E;
}
