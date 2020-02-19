/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strrchr(const char *s, int c)
{
    char *p = (char *)(s + strlen(s));

    while (p >= s) {
        if (*p == (char)c) return p;
        p--;
    }

    return NULL;
}
