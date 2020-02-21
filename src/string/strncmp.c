/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

int strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned char *c1 = (unsigned char*)s1;
    unsigned char *c2 = (unsigned char*)s2;

    while (n > 0 && *c1 == *c2 && *c1 != '\0') {
        c1++;
        c2++;
        n--;
    }

    if (n == 0) return 0;
    return *c1 - *c2;
}
