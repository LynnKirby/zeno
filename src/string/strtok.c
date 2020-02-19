/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strtok(char *restrict str, const char *restrict delim)
{
    static char *p = NULL;

    if (str) {
        p = str;
    } else if (!p) {
        return NULL;
    }

    str = p + strspn(p, delim);
    p   = str + strcspn(str, delim);

    if (p == str) {
        p = NULL;
        return NULL;
    }

    if (*p != '\0') {
        *p = '\0';
        p++;
    } else {
        p = NULL;
    }

    return str;
}
