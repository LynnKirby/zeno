/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fetestexcept(int excepts) */
ENTRY(fetestexcept)
    mov 4(%esp), %ecx
    sub $4, %esp

    and $0x3F, %ecx /* excepts &= FE_ALL_EXCEPT */
    stmxcsr (%esp)  /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    fnstsw %ax      /* EAX = x87 status word */
    or (%esp), %eax /* EAX |= mxcsr */

    and %ecx, %eax  /* return EAX & excepts */
    add $4, %esp
    ret
END(fetestexcept)
