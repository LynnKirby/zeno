/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int setjmp(jmp_buf buf) */
ENTRY(setjmp)
     /* EAX = &buf->__jmp_buf */
    mov 4(%esp), %eax

    /* save registers */
    mov %ebx,   (%eax)
    mov %esi,  4(%eax)
    mov %edi,  8(%eax)
    mov %ebp, 12(%eax)

    /* save caller ESP */
    lea 4(%esp), %ecx
    mov %ecx, 16(%eax)

    /* save caller EIP */
    mov (%esp), %ecx
    mov %ecx, 20(%eax)

    /* return 0 */
    xor %eax, %eax
    ret
END(setjmp)
