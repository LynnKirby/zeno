/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

void *memccpy(void *restrict dest, const void *restrict src, int c, size_t n)
{
    unsigned char *d       = dest;
    const unsigned char *s = src;

    while (n != 0) {
        *d = *s;
        d++;

        if (*s == (unsigned char)c) return d;

        s++;
        n--;
    }

    return NULL;
}
