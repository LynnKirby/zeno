/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fegetenv(fenv_t *envp) */
ENTRY(fegetenv)
    mov 4(%esp), %eax
    fnstenv (%eax)   /* fnstenv(envp) */
    /* FNSTENV clears the exception mask but this function shouldn't modify the
     * environment, so we need to restore the old environment. */
    fldenv (%eax)    /* fldenv(envp) */
    stmxcsr 28(%eax) /* stmxcsr(&envp->__mxcsr) */
    xor %eax, %eax   /* return 0 */
    ret
END(fegetenv)
