/*
 * SPDX-License-Identifier: CC0-1.0
 * Linux i386 entry point.
 *
 * Stack layout on entry:
 *
 *   ESP + 0             argc
 *   ESP + 4             argv[0]
 *   ESP + 4*(argc + 1)  NULL
 *   ESP + 4*(argc + 2)  envp[0]
 *
 * EDX contains rtld_fini function pointer on entry.
 *
 * See also:
 * - System V Intel386 psABI, section 2.3 Process Initialization
 *   https://github.com/hjl-tools/x86-psABI/wiki/intel386-psABI-1.1.pdf
 */

#include "basic/asm.h"

ENTRY(_start)
    .cfi_undefined %eip /* prevent debugger unwinding to nonexistent caller */
    xor %ebp, %ebp /* mark this as the lowest stack frame */
    pop %eax       /* save argc */
    mov %esp, %ebx /* save argv */
    and $-16, %esp /* align stack pointer */
    push %eax      /* push garbage to maintain alignment (args are 28-byte)*/
    push %esp             /* arg 7: stack_end */
    push %edx             /* arg 6: rtld_fini */
    push $__libc_csu_fini /* arg 5: fini */
    push $__libc_csu_init /* arg 4: init */
    push %ebx             /* arg 3: argv */
    push %eax             /* arg 2: argc */
    push $main            /* arg 1: main */
    call __libc_start_main
    hlt /* we shouldn't return from main, so just crash */
END(_start)
