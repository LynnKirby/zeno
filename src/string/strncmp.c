/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

int strncmp(const char *s1, const char *s2, size_t n)
{
    while (*s1 == *s2 && *s1 != '\0' && n > 0) {
        s1++;
        s2++;
        n--;
    }

    return (unsigned char)*s1 - (unsigned char)*s2;
}
