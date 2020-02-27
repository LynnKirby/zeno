/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fesetexcept(int excepts) */
ENTRY(fesetexcept)
    and $0x3F, %edi   /* excepts &= FE_ALL_EXCEPT */
    stmxcsr -4(%rsp)  /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    or %edi, -4(%rsp) /* mxcsr |= excepts */
    ldmxcsr -4(%rsp)  /* ldmxcsr(&mxcsr) */
    xor %eax, %eax    /* return 0 */
    ret
END(fesetexcept)
