/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strncpy(char *restrict dest, const char *restrict src, size_t n)
{
    char *d = dest;

    while (n != 0) {
        *d = *src;
        d++;
        n--;
        if (*src == '\0') break;
        src++;
    }

    while (n != 0) {
        *d = '\0';
        d++;
        n--;
    }

    return dest;
}
