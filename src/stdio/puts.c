/* SPDX-License-Identifier: CC0-1.0 */

#include <stdio.h>

int puts(const char *s)
{
    if (fputs(s, stdout) == EOF) return EOF;
    if (fputs("\n", stdout) == EOF) return EOF;
    return 1;
}
