/* SPDX-License-Identifier: CC0-1.0 */

#include <string.h>

size_t strlen(const char *s)
{
    const char *end = s;
    while (*end != '\0') end++;
    return end - s;
}
