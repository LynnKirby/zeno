/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * Bump-pointer allocator with 10 MB static size. Used at this stage of
 * development so we can allocate things without having to write or import a
 * real malloc implementation.
 */

#include "basic/cdefs.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (10 * 1024 * 1024)

static char data[DATA_SIZE];
static char *current;
size_t count;

void *malloc(size_t size)
{
    size = size + 16;

    if (count + size > DATA_SIZE) return NULL;

    if (!current) {
        current = data;
    }

    char *allocation = (char *)(((uintptr_t)current + 15) & ~15);
    current += size;
    return allocation;
}

void *calloc(size_t n, size_t size)
{
    size *= n; /* Who cares about overflow, really? */
    char *a = malloc(size);
    return memset(a, 0, size);
}

void free(void *p)
{
    UNUSED_PARAM(p);
    /* Nothing! */
}

