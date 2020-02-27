/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fegetround(void) */
ENTRY(fegetround)
    sub $4, %esp

    stmxcsr (%esp)   /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    mov (%esp), %eax
    shr $3, %eax     /* mxcsr >>= MXCSR_ROUNDING_SHIFT */
    and $0xC00, %eax /* mxcsr &= ROUNDING_MASK */

    add $4, %esp
    ret              /* return mxcsr */
END(fegetround)
