/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

size_t strspn(const char *s1, const char *s2)
{
    size_t len = 0;

    while (*s1 != '\0') {
        if (!strchr(s2, *s1)) {
            return len;
        }
        len++;
        s1++;
    }

    return len;
}
