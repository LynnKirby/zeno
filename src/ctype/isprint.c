/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int isprint(int c)
{
    return c >= 0x20 && c <= 0x7E;
}
