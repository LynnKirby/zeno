/*
 * SPDX-License-Identifier: CC0-1.0
 * i386 ELF init/fini function prologues.
 */

.section .init, "ax", @progbits
.global _init
.type _init, @function
_init:
    sub $12, %esp

.section .fini, "ax", @progbits
.global _fini
.type _fini, @function
_fini:
    sub $12, %esp
