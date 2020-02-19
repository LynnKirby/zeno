/* SPDX-License-Identifier: CC0-1.0 */

#include <ctype.h>

int isalpha(int c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
