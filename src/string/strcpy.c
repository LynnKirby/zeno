/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strcpy(char *restrict dest, const char *restrict src)
{
    char *d = dest;

    for (;;) {
        *d = *src;
        if (*d == '\0') break;
        src++;
        d++;
    }

    return dest;
}
