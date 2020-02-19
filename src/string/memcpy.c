/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

void *memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    char *d       = dest;
    const char *s = src;

    while(n != 0) {
        *d = *s;
        d++;
        s++;
        n--;
    }

    return dest;
}
