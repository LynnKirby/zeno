/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fegetround(void) */
ENTRY(fegetround)
    stmxcsr -8(%rsp)   /* uint32_t mxcsr; stmxcsr(&mxcsr) */
    mov -8(%rsp), %eax
	shr $3, %eax       /* mxcsr >>= MXCSR_ROUNDING_SHIFT */
	and $0xC00, %eax   /* mxcsr &= ROUNDING_MASK */
	ret                /* return mxcsr */
END(fegetround)
