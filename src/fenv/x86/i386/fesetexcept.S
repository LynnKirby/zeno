/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fesetexcept(int excepts) */
ENTRY(fesetexcept)
    mov 4(%esp), %eax
    sub $4, %esp

    and $0x3F, %eax /* excepts &= FE_ALL_EXCEPT */
    stmxcsr (%esp)  /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    or %eax, (%esp) /* mxcsr |= excepts */
    ldmxcsr (%esp)  /* ldmxcsr(&mxcsr) */

    xor %eax, %eax  /* return 0 */
    add $4, %esp
    ret
END(fesetexcept)
