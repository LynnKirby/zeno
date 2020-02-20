/* SPDX-License-Identifier: CC0-1.0 */

#ifndef INITFINI_INITFINI_H
#define INITFINI_INITFINI_H

typedef void (*StructorFn)(void);
typedef void (*CxaStructorFn)(void *);

/*
 * Internal API.
 */

void __libc_run_atexit_handlers(void);
void __libc_init(void);

/*
 * Subsystem initializers.
 */

void __libc_init_rand(void);

#endif
