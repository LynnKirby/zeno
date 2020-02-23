/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int setjmp(jmp_buf buf) */
ENTRY(setjmp)
    /* save registers */
    mov %rbx,   (%rdi)
    mov %rbp,  8(%rdi)
    mov %r12, 16(%rdi)
    mov %r13, 24(%rdi)
    mov %r14, 32(%rdi)
    mov %r15, 40(%rdi)

    /* save caller RSP */
    lea 8(%rsp), %rax
    mov %rax, 48(%rdi)

    /* save caller RIP */
    mov (%rsp), %rax
    mov %rax, 56(%rdi)

    /* return 0 */
    xor %rax, %rax
    ret
END(setjmp)
