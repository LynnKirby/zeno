/*
 * SPDX-License-Identifier: CC0-1.0
 * bits/fenv.h private header - x86 version
 */

#ifndef _BITS_FENV_H
#define _BITS_FENV_H

#include <bits/stdint.h>

#define FE_INVALID   0x01
#define FE_DENORMAL  0x02
#define FE_DIVBYZERO 0x04
#define FE_OVERFLOW  0x08
#define FE_UNDERFLOW 0x10
#define FE_INEXACT   0x20

#define FE_ALL_EXCEPT                                                     \
    (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO | FE_OVERFLOW | FE_UNDERFLOW \
     | FE_INEXACT)

#define FE_TONEAREST  0x000
#define FE_DOWNWARD   0x400
#define FE_UPWARD     0x800
#define FE_TOWARDZERO 0xC00

typedef unsigned short fexcept_t;
typedef unsigned short femode_t;

typedef struct {
    unsigned short __control_word;
    unsigned short __unused1;
    unsigned short __status_word;
    unsigned short __unused2;
    unsigned short __tags;
    unsigned short __unused3;
    unsigned __eip;
    unsigned short __cs_selector;
    unsigned __opcode : 11;
    unsigned __unused4 : 5;
    unsigned __data_offset;
    unsigned short __data_selector;
    unsigned short __unused5;
    unsigned __mxcsr;
} fenv_t;

#define FE_DFL_ENV  ((const fenv_t *)-1)
#define FE_DFL_MODE ((const femode_t *)-1)

#endif
