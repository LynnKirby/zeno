/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/asm.h"

/* int fegetenv(fenv_t *envp) */
ENTRY(fegetenv)
    fnstenv (%rdi)   /* fnstenv(envp) */
    /* FNSTENV clears the exception mask but this function shouldn't modify the
     * environment, so we need to restore the old environment. */
    fldenv (%rdi)    /* fldenv(envp) */
    stmxcsr 28(%rdi) /* stmxcsr(&envp->__mxcsr) */
    xor %eax, %eax   /* return 0 */
    ret
END(fegetenv)
