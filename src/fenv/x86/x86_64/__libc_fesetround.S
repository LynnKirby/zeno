/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int __fesetround(int round) */
ENTRY(__libc_fesetround)
    fnstcw -2(%rsp)      /* uint16_t control; fnstcw(&control) */
    andb $0xF3, -1(%rsp) /* control &= ~ROUNDING_MASK */
    or %edi, -2(%rsp)    /* control |= round */
    fldcw -2(%rsp)       /* fldcw(&control) */

    stmxcsr -4(%rsp)     /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    andb $0x9F, -3(%rsp) /* mxcsr & ~(ROUNDING_MASK << 3) */
    shl $3, %edi         /* round <<= 3 */
    or %edi, -4(%rsp)    /* mxcsr |= round */
    ldmxcsr -4(%rsp)     /* ldmxcsr(&round) */

    xor %eax, %eax       /* return 0*/
	ret
END(__libc_fesetround)
