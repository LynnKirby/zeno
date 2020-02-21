/* SPDX-License-Identifier: CC0-1.0 */

#ifndef INITFINI_IMPL_H
#define INITFINI_IMPL_H

typedef void (*StructorFn)(void);
typedef void (*CxaStructorFn)(void *);

void __libc_run_atexit_handlers(void);

#endif
