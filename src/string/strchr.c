/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strchr(const char *s, int c)
{
    do {
        if (*s == (unsigned char)c) {
            return (void *)s;
        }
        s++;
    } while (s[-1] != '\0');

    return NULL;
}
