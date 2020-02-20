/* SPDX-License-Identifier: CC0-1.0 */

#include "initfini.h"
#include <stdbool.h>
#include <stddef.h>

/* TODO: Should dynamically allocate more slots. */

/* 32 user-registerable required by standard. Plus 2 that we use internally. */
#define MAX_COUNT 34

struct {
    union {
        CxaStructorFn cxa;
        StructorFn atexit;
    } fn;
    void *arg;
    bool is_cxa;
} funcs[MAX_COUNT];

static unsigned count;

int __cxa_atexit(CxaStructorFn fn, void *arg, void *dso_handle)
{
    if (count >= MAX_COUNT) return -1;
    funcs[count].fn.cxa = fn;
    funcs[count].arg    = arg;
    funcs[count].is_cxa = true;
    count += 1;
    return 0;
}

int atexit(StructorFn fn)
{
    if (count >= MAX_COUNT) return -1;
    funcs[count].fn.atexit = fn;
    funcs[count].is_cxa    = false;
    count += 1;
    return 0;
}

void __libc_run_atexit_handlers(void)
{
    if (count == 0) return;

    for (size_t i = count; i > 0; --i) {
        size_t idx = i - 1;
        if (funcs[idx].is_cxa) {
            funcs[idx].fn.cxa(funcs[idx].arg);
        } else {
            funcs[idx].fn.atexit();
        }
    }
}
