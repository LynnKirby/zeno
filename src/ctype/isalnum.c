/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int isalnum(int c)
{
    return isalpha(c) || isdigit(c);
}
