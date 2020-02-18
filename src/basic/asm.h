/*
 * SPDX-License-Identifier: CC0-1.0
 * Assembly utilities.
 */

#ifndef BASIC_ASM_H
#define BASIC_ASM_H

/* Note: alignment and function types may need to change in the future to
 * support other architectures. The current values are correct for x86. */

/* Start of an assembly function. */
#define ENTRY(f)        \
    .text;              \
    .global f;          \
    .balign 16;         \
    .type f, @function; \
    f:                  \
    .cfi_startproc

/* End of an assembly function. */
#define END(f)    \
    .cfi_endproc; \
    .size f, .- f;

#endif
