/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * zeno/limits.h private header - private limits.h definitions
 */

#ifndef _ZENO_LIMITS_H
#define _ZENO_LIMITS_H

/* TODO: Fill out the rest. This is all that's needed for stdint.h to work. */

#ifdef __LONG_WIDTH__
#define _ZENO_LONG_WIDTH __LONG_WIDTH__
#elif __LONG_MAX__ == 0x7fffffff
#define _ZENO_LONG_WIDTH 32
#elif __LONG_MAX__ == 0x7fffffffffffffff
#define _ZENO_LONG_WIDTH 64
#else
#error "Could not determine _ZENO_LONG_WIDTH."
#endif

#endif
