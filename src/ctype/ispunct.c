/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int ispunct(int c)
{
    return isprint(c) && !(isspace(c) || isalnum(c));
}
