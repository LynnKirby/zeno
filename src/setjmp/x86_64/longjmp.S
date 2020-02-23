/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int longjump(jmp_buf buf, int value) */
ENTRY(longjmp)
    /* RAX = value == 0 ? 1 : value */
    mov %rsi, %rax
    test %rax, %rax
    jnz 1f
    inc %rax
1:

    /* restore registers */
    mov   (%rdi), %rbx
    mov  8(%rdi), %rbp
    mov 16(%rdi), %r12
    mov 24(%rdi), %r13
    mov 32(%rdi), %r14
    mov 40(%rdi), %r15

    /* restore RSP */
    mov 48(%rdi), %rdx
    mov %rdx, %rsp

    /* restore RIP (by jumping to it) */
    mov 56(%rdi), %rdx
    jmp *%rdx
END(longjmp)
