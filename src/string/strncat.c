/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

char *strncat(char *restrict dest, const char *restrict src, size_t n)
{
    char *result = dest;
    dest += strlen(dest);

    while(n != 0 && *src != '\0') {
        *dest = *src;
        dest++;
        src++;
        n--;
    }

    *dest = '\0';

    return result;
}
