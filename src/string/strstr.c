/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strstr(const char *s1, const char *s2)
{
    if (s2[0] == '\0') return (char *)s1;

    while (*s1 != '\0') {
        const char *p1 = s1;
        const char *p2 = s2;

        while (*p1 == *p2 && *p1 != '\0' && *p2 != '\0') {
            p1++;
            p2++;
        }

        if (*p2 == '\0') {
            return (char *)s1;
        }

        s1++;
    }

    return NULL;
}
