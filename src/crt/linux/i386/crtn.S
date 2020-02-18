/*
 * SPDX-License-Identifier: CC0-1.0
 * i386 ELF init/fini function epilogues.
 */

.section .init, "ax", @progbits
    add $12, %esp
    ret

.section .fini, "ax", @progbits
    add $12, %esp
    ret
