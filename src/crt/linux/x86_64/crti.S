/*
 * SPDX-License-Identifier: CC0-1.0
 * x86-64 ELF init/fini function prologues.
 */

.section .init, "ax", @progbits
.global _init
.type _init, @function
_init:
    push %rax

.section .fini, "ax", @progbits
.global _fini
.type _fini, @function
_fini:
    push %rax
