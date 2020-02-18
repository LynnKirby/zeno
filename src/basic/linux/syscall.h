/*
 * SPDX-License-Identifier: CC0-1.0
 * Linux syscall functions.
 */

#ifndef BASIC_LINUX_SYSCALL_H
#define BASIC_LINUX_SYSCALL_H

#if defined(__i386__)
#include "basic/linux/i386/syscall.h"
#elif defined(__x86_64__)
#include "basic/linux/x86_64/syscall.h"
#else
#error "Not implemented for this architecture."
#endif

#endif
