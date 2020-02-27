/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int __libc_fesetenv(const fenv_t *envp) */
ENTRY(__libc_fesetenv)
    mov 4(%esp), %eax
    fldenv (%eax)    /* fldenv(envp) */
    ldmxcsr 28(%eax) /* ldmxcsr(&envp->__mxcsr) */
    xor %eax, %eax   /* return 0 */
    ret
END(__libc_fesetenv)
