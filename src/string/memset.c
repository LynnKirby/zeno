/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

void *memset(void *dest, int c, size_t n)
{
    unsigned char *s = dest;

    while (n != 0) {
        *s = (unsigned char)c;
        s++;
        n--;
    }

    return dest;
}
