/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

void *memchr(const void *s, int c, size_t n)
{
    const unsigned char *p = s;

    while (n != 0) {
        if (*p == (unsigned char)c) {
            return (void *)p;
        }
        p++;
        n--;
    }

    return NULL;
}
