/*
 * SPDX-License-Identifier: CC0-1.0
 * stdlib.h standard C header
 */

#ifndef _STDLIB_H
#define _STDLIB_H

#ifdef __cplusplus
extern "C" {
#endif

/*
 * C18 7.22.4 Communication with the environment.
 */

int atexit(void(*)(void));
_Noreturn void exit(int);
_Noreturn void _Exit(int);

#ifdef __cplusplus
}
#endif

#endif
