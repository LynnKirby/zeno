/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strpbrk(const char *s1, const char *s2)
{
    while (*s1 != '\0') {
        if (strchr(s2, *s1)) {
            return (char *)s1;
        }
        s1++;
    }

    return NULL;
}
