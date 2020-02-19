/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

void *memmove(void *dest, const void *src, size_t n)
{
    if (dest == src) return dest;
    if (n == 0) return dest;

    const char *s = src;
    char *d       = dest;

    /* Copy forward. The current memcpy implementation does that. */
    if (d < s) {
        return memcpy(d, s, n);
    }

    /* Otherwise copy backwards. */
    s += n - 1;
    d += n - 1;

    while (n != 0) {
        *d = *s;
        d--;
        s--;
        n--;
    }

    return dest;
}
