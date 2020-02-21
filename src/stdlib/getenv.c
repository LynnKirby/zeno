/* SPDX-License-Identifier: CC0-1.0 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern char **environ;

char *getenv(const char *name)
{
    if (!environ || name[0] == '\0') return NULL;

    size_t len = strlen(name);

    for (char **entry = environ; *entry; ++entry) {
        if (strncmp(name, *entry, len) == 0 && (*entry)[len] == '=') {
            return *entry + len + 1;
        }
    }

    return NULL;
}
