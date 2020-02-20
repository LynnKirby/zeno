/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * signal.h - signal handling
 */

#ifndef _SIGNAL_H
#define _SIGNAL_H

#include <sys/cdefs.h>
#include <bits/types.h>
#include <bits/signal-values.h>

typedef __sig_atomic_t sig_atomic_t;

typedef void(* __signal_handler_t)(int);

#define SIG_ERR ((__signal_handler_t) -1)
#define SIG_DFL ((__signal_handler_t) 0)
#define SIG_IGN ((__signal_handler_t) 1)

__BEGIN_DECLS
__signal_handler_t signal(int, __signal_handler_t);
int raise(int);
__END_DECLS

#endif
