/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fetestexcept(int excepts) */
ENTRY(fetestexcept)
    and $0x3F, %edi   /* excepts &= FE_ALL_EXCEPT */
    stmxcsr -4(%rsp)  /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    fnstsw %ax        /* EAX = x87 status word */
    or -4(%rsp), %eax /* EAX |= mxcsr */
    and %edi, %eax    /* return EAX & excepts */
    ret
END(fetestexcept)
