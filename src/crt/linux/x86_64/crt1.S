/*
 * SPDX-License-Identifier: CC0-1.0
 * Linux x86_64 entry point.
 *
 * Stack layout on entry:
 *
 *   RSP + 0             argc
 *   RSP + 8             argv[0]
 *   RSP + 8*(argc + 1)  NULL
 *   RSP + 8*(argc + 2)  envp[0]
 *
 * RDX contains rtld_fini function pointer on entry.
 *
 * See also:
 * - System V x86-64 psABI, section 3.4 Process Initialization
 *   https://github.com/hjl-tools/x86-psABI/wiki/x86-64-psABI-1.0.pdf
 */

#include "basic/asm.h"

ENTRY(_start)
    .cfi_undefined %rip /* prevent debugger unwinding to nonexistent caller */
    xor %rbp, %rbp      /* mark this as the lowest stack frame */
    pop %rsi                   /* arg 2: argc */
    mov %rdx, %r9              /* arg 6: rtld_fini */
    mov %rsp, %rdx             /* arg 3: argv */
    and $-16, %rsp             /* align stack pointer */
    push %rsp                  /* push garbage to maintain alignment */
    push %rsp                  /* arg 7: stack_end */
    mov $__libc_csu_fini, %r8  /* arg 5: fini */
    mov $__libc_csu_init, %rcx /* arg 4: init */
    mov $main, %rdi            /* arg 1: main */
    call __libc_start_main
    hlt /* we shouldn't return from main, so just crash */
END(_start)
