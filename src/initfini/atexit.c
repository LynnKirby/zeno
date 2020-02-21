/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "initfini/impl.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#define SLOT_SIZE 32

typedef struct {
    union {
        CxaStructorFn cxa;
        StructorFn atexit;
    } fn;
    void *arg;
    bool is_cxa;
} ExitFn;

typedef struct Node {
    struct Node *next;
    size_t count;
    ExitFn slots[SLOT_SIZE];
} Node;

static Node static_slots;
static Node *head = &static_slots;

static ExitFn *new_exitfn(void)
{
    if (head->count >= SLOT_SIZE) {
        Node *new_head = malloc(sizeof(Node));
        if (!new_head) return NULL;
        new_head->next  = head;
        new_head->count = 0;
        head            = new_head;
    }

    ExitFn *e = &head->slots[head->count];
    head->count++;
    return e;
}

int __cxa_atexit(CxaStructorFn fn, void *arg, void *dso_handle)
{
    UNUSED_PARAM(dso_handle);

    ExitFn *e = new_exitfn();
    if (!e) return -1;
    e->fn.cxa = fn;
    e->arg    = arg;
    e->is_cxa = true;
    return 0;
}

int atexit(StructorFn fn)
{
    ExitFn *e = new_exitfn();
    if (!e) return -1;
    e->fn.atexit = fn;
    e->is_cxa    = false;
    return 0;
}

void __libc_run_atexit_handlers(void)
{
    /* Go through the stack. Top is most recently registered. */
    for (Node *node = head; node; node = node->next) {
        /* Iterate slots backwards. Higher index is most recently registered. */
        for (size_t i = node->count; i > 0; i--) {
            ExitFn *e = &node->slots[i - 1];
            if (e->is_cxa) {
                e->fn.cxa(e->arg);
            } else {
                e->fn.atexit();
            }
        }
    }
}
