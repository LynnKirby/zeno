/* SPDX-License-Identifier: CC0-1.0 */

#include <stdio.h>

int puts(const char *s)
{
    return fputs(s, stdout);
}
