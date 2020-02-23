/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int longjump(jmp_buf buf, int value) */
ENTRY(longjmp)
    /* ECX = &buf->__jmp_buf */
    mov 4(%esp), %ecx

    /* EAX = value == 0 ? 1 : value */
    mov 8(%esp), %eax
    test %eax, %eax
    jnz 1f
    inc %eax
1:

    /* restore registers */
    mov   (%ecx), %ebx
    mov  4(%ecx), %esi
    mov  8(%ecx), %edi
    mov 12(%ecx), %ebp

    /* restore ESP */
    mov 16(%ecx), %edx
    mov %edx, %esp

    /* restore EIP (by jumping to it) */
    mov 20(%ecx), %edx
    jmp *%edx
END(longjmp)
