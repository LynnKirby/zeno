/*
 * SPDX-License-Identifier: CC0-1.0
 * setjmp.h standard C header
 */

#ifndef _SETJMP_H
#define _SETJMP_H

#include <bits/setjmp.h>

/* TODO: Update with signal information when implemented. */
typedef struct __jmp_buf_tag {
    __jmp_buf __jb;
} jmp_buf[1];

int setjmp(jmp_buf);
_Noreturn void longjmp(jmp_buf, int);
#define setjmp setjmp

#endif
