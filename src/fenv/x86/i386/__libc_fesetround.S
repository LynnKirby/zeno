/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int __fesetround(int round) */
ENTRY(__libc_fesetround)
    mov 4(%esp), %eax
    sub $4, %esp

    fnstcw (%esp)       /* uint16_t control; fnstcw(&control) */
    andb $0xF3, 1(%esp) /* control &= ~ROUNDING_MASK */
    or %eax, (%esp)     /* control |= round */
    fldcw (%esp)        /* fldcw(&control) */

    stmxcsr (%esp)      /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    andb $0x9F, 1(%esp) /* mxcsr & ~(ROUNDING_MASK << 3) */
    shl $3, %eax        /* round <<= 3 */
    or %eax, (%esp)     /* mxcsr |= round */
    ldmxcsr (%esp)      /* ldmxcsr(&round) */

    xor %eax, %eax      /* return 0*/
    add $4, %esp
    ret
END(__libc_fesetround)
