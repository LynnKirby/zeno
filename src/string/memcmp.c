/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *c1 = s1;
    const unsigned char *c2 = s2;

    while (n != 0) {
        if (*c1 != *c2) {
            return *c1 < *c2 ? -1 : 1;
        }

        n--;
        c1++;
        c2++;
    }

    return 0;
}
