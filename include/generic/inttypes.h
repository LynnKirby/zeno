/*
 * SPDX-License-Identifier: CC0-1.0
 * inttypes.h standard C header
 */

#ifndef _INTTYPES_H
#define _INTTYPES_H

#include <stdint.h>
#include <bits/limits.h>
#include <bits/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Functions for greatest-width integer types.
 */

typedef struct {
    intmax_t quot;
    intmax_t rem;
} imaxdiv_t;

intmax_t imaxabs(intmax_t);
imaxdiv_t imaxdiv(intmax_t, intmax_t);
intmax_t strtoimax(const char *__libc_restrict, char **__libc_restrict, int);
uintmax_t strtoumax(const char *__libc_restrict, char **__libc_restrict, int);

intmax_t wcstoimax(
    const __libc_wchar_t *__libc_restrict,
    __libc_wchar_t **__libc_restrict,
    int);

uintmax_t wcstoumax(
    const __libc_wchar_t *__libc_restrict,
    __libc_wchar_t **__libc_restrict,
    int);

/*
 * Macros for format specifiers.
 */

#if _LIBC_LONG_WIDTH == 64
#define __PRI64 "l"
#define __SCN64 "l"
#else
#define __PRI64 "ll"
#define __SCN64 "ll"
#endif

#if _LIBC_INTPTR_WIDTH == 64
#define __PRIPTR __PRI64
#define __SCNPTR __SCN64
#else
#define __PRIPTR ""
#define __SCNPTR ""
#endif

#if _LIBC_INT_FAST8_WIDTH == _LIBC_CHAR_WIDTH
#define __PRIFAST8 ""
#define __SCNFAST8 "hh"
#elif _LIBC_INT_FAST8_WIDTH == _LIBC_SHRT_WIDTH
#define __PRIFAST8 ""
#define __SCNFAST8 "h"
#elif _LIBC_INT_FAST8_WIDTH == _LIBC_INT_WIDTH
#define __PRIFAST8 ""
#define __SCNFAST8 ""
#elif _LIBC_INT_FAST8_WIDTH == _LIBC_LONG_WIDTH
#define __PRIFAST8 "l"
#define __SCNFAST8 "l"
#elif _LIBC_INT_FAST8_WIDTH == _LIBC_LLONG_WIDTH
#define __PRIFAST8 "ll"
#define __SCNFAST8 "ll"
#endif

#if _LIBC_INT_FAST16_WIDTH == _LIBC_SHRT_WIDTH
#define __PRIFAST16 ""
#define __SCNFAST16 "h"
#elif _LIBC_INT_FAST16_WIDTH == _LIBC_INT_WIDTH
#define __PRIFAST16 ""
#define __SCNFAST16 ""
#elif _LIBC_INT_FAST16_WIDTH == _LIBC_LONG_WIDTH
#define __PRIFAST16 "l"
#define __SCNFAST16 "l"
#elif _LIBC_INT_FAST16_WIDTH == _LIBC_LLONG_WIDTH
#define __PRIFAST16 "ll"
#define __SCNFAST16 "ll"
#endif

#if _LIBC_INT_FAST32_WIDTH == _LIBC_INT_WIDTH
#define __PRIFAST32 ""
#define __SCNFAST32 ""
#elif _LIBC_INT_FAST32_WIDTH == _LIBC_LONG_WIDTH
#define __PRIFAST32 "l"
#define __SCNFAST32 "l"
#elif _LIBC_INT_FAST32_WIDTH == _LIBC_LLONG_WIDTH
#define __PRIFAST32 "ll"
#define __SCNFAST32 "ll"
#endif

#if _LIBC_INT_FAST64_WIDTH == _LIBC_LONG_WIDTH
#define __PRIFAST64 "l"
#define __SCNFAST64 "l"
#elif _LIBC_INT_FAST64_WIDTH == _LIBC_LLONG_WIDTH
#define __PRIFAST64 "ll"
#define __SCNFAST64 "ll"
#endif

/* fprintf macros for signed integers */

#define PRId8  "d"
#define PRId16 "d"
#define PRId32 "d"
#define PRId64 __PRI64 "d"

#define PRIdLEAST8  PRId8
#define PRIdLEAST16 PRId16
#define PRIdLEAST32 PRId32
#define PRIdLEAST64 PRId64

#define PRIdFAST8  __PRIFAST8 "d"
#define PRIdFAST16 __PRIFAST16 "d"
#define PRIdFAST32 __PRIFAST32 "d"
#define PRIdFAST64 __PRIFAST64 "d"

#define PRIdMAX "jd"
#define PRIdPTR __PRIPTR "d"

#define PRIi8  "i"
#define PRIi16 "i"
#define PRIi32 "i"
#define PRIi64 __PRI64 "i"

#define PRIiLEAST8  PRIi8
#define PRIiLEAST16 PRIi16
#define PRIiLEAST32 PRIi32
#define PRIiLEAST64 PRIi64

#define PRIiFAST8  __PRIFAST8 "i"
#define PRIiFAST16 __PRIFAST16 "i"
#define PRIiFAST32 __PRIFAST32 "i"
#define PRIiFAST64 __PRIFAST64 "i"

#define PRIiMAX "ji"
#define PRIiPTR __PRIPTR "i"

/* fprintf macros for unsigned integers */

#define PRIo8  "o"
#define PRIo16 "o"
#define PRIo32 "o"
#define PRIo64 __PRI64 "o"

#define PRIoLEAST8  PRIo8
#define PRIoLEAST16 PRIo16
#define PRIoLEAST32 PRIo32
#define PRIoLEAST64 PRIo64

#define PRIoFAST8  __PRIFAST8 "o"
#define PRIoFAST16 __PRIFAST16 "o"
#define PRIoFAST32 __PRIFAST32 "o"
#define PRIoFAST64 __PRIFAST64 "o"

#define PRIoMAX "jo"
#define PRIoPTR __PRIPTR "o"

#define PRIu8  "u"
#define PRIu16 "u"
#define PRIu32 "u"
#define PRIu64 __PRI64 "u"

#define PRIuLEAST8  PRIu8
#define PRIuLEAST16 PRIu16
#define PRIuLEAST32 PRIu32
#define PRIuLEAST64 PRIu64

#define PRIuFAST8  __PRIFAST8 "u"
#define PRIuFAST16 __PRIFAST16 "u"
#define PRIuFAST32 __PRIFAST32 "u"
#define PRIuFAST64 __PRIFAST64 "u"

#define PRIuMAX "ju"
#define PRIuPTR __PRIPTR "u"

#define PRIx8  "x"
#define PRIx16 "x"
#define PRIx32 "x"
#define PRIx64 __PRI64 "x"

#define PRIxLEAST8  PRIx8
#define PRIxLEAST16 PRIx16
#define PRIxLEAST32 PRIx32
#define PRIxLEAST64 PRIx64

#define PRIxFAST8  __PRIFAST8 "x"
#define PRIxFAST16 __PRIFAST16 "x"
#define PRIxFAST32 __PRIFAST32 "x"
#define PRIxFAST64 __PRIFAST64 "x"

#define PRIxMAX "jx"
#define PRIxPTR __PRIPTR "x"

#define PRIX8  "X"
#define PRIX16 "X"
#define PRIX32 "X"
#define PRIX64 __PRI64 "X"

#define PRIXLEAST8  PRIX8
#define PRIXLEAST16 PRIX16
#define PRIXLEAST32 PRIX32
#define PRIXLEAST64 PRIX64

#define PRIXFAST8  __PRIFAST8 "X"
#define PRIXFAST16 __PRIFAST16 "X"
#define PRIXFAST32 __PRIFAST32 "X"
#define PRIXFAST64 __PRIFAST64 "X"

#define PRIXMAX "jX"
#define PRIXPTR __PRIPTR "X"

/* fscanf macros for signed integers */

#define SCNd8  "hhd"
#define SCNd16 "hd"
#define SCNd32 "d"
#define SCNd64 __SCN64 "d"

#define SCNdLEAST8  SCNd8
#define SCNdLEAST16 SCNd16
#define SCNdLEAST32 SCNd32
#define SCNdLEAST64 SCNd64

#define SCNdFAST8  __SCNFAST8 "d"
#define SCNdFAST16 __SCNFAST16 "d"
#define SCNdFAST32 __SCNFAST32 "d"
#define SCNdFAST64 __SCNFAST64 "d"

#define SCNdMAX "jd"
#define SCNdPTR __SCNPTR "d"

#define SCNi8  "hhi"
#define SCNi16 "hi"
#define SCNi32 "i"
#define SCNi64 __SCN64 "i"

#define SCNiLEAST8  SCNi8
#define SCNiLEAST16 SCNi16
#define SCNiLEAST32 SCNi32
#define SCNiLEAST64 SCNi64

#define SCNiFAST8  __SCNFAST8 "i"
#define SCNiFAST16 __SCNFAST16 "i"
#define SCNiFAST32 __SCNFAST32 "i"
#define SCNiFAST64 __SCNFAST64 "i"

#define SCNiMAX "ji"
#define SCNiPTR __SCNPTR "i"

/* fscanf macros for unsigned integers */

#define SCNo8  "hho"
#define SCNo16 "ho"
#define SCNo32 "o"
#define SCNo64 __SCN64 "o"

#define SCNoLEAST8  SCNo8
#define SCNoLEAST16 SCNo16
#define SCNoLEAST32 SCNo32
#define SCNoLEAST64 SCNo64

#define SCNoFAST8  __SCNFAST8 "o"
#define SCNoFAST16 __SCNFAST16 "o"
#define SCNoFAST32 __SCNFAST32 "o"
#define SCNoFAST64 __SCNFAST64 "o"

#define SCNoMAX "jo"
#define SCNoPTR __SCNPTR "o"

#define SCNu8  "hhu"
#define SCNu16 "hu"
#define SCNu32 "u"
#define SCNu64 __SCN64 "u"

#define SCNuLEAST8  SCNu8
#define SCNuLEAST16 SCNu16
#define SCNuLEAST32 SCNu32
#define SCNuLEAST64 SCNu64

#define SCNuFAST8  __SCNFAST8 "u"
#define SCNuFAST16 __SCNFAST16 "u"
#define SCNuFAST32 __SCNFAST32 "u"
#define SCNuFAST64 __SCNFAST64 "u"

#define SCNuMAX "ju"
#define SCNuPTR __SCNPTR "u"

#define SCNx8  "hhx"
#define SCNx16 "hx"
#define SCNx32 "x"
#define SCNx64 __SCN64 "x"

#define SCNxLEAST8  SCNx8
#define SCNxLEAST16 SCNx16
#define SCNxLEAST32 SCNx32
#define SCNxLEAST64 SCNx64

#define SCNxFAST8  __SCNFAST8 "x"
#define SCNxFAST16 __SCNFAST16 "x"
#define SCNxFAST32 __SCNFAST32 "x"
#define SCNxFAST64 __SCNFAST64 "x"

#define SCNxMAX "jx"
#define SCNxPTR __SCNPTR "x"

#ifdef __cplusplus
}
#endif

#endif
