/*
 * SPDX-License-Identifier: CC0-1.0
 * x86-64 ELF init/fini function epilogues.
 */

.section .init, "ax", @progbits
    pop %rax
    ret

.section .fini, "ax", @progbits
    pop %rax
    ret
