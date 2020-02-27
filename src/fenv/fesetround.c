/* SPDX-License-Identifier: CC0-1.0 */

#include "fenv/impl.h"
#include <fenv.h>

int fesetround(int round)
{
    switch (round) {
#ifdef FE_DOWNWARD
    case FE_DOWNWARD:
#endif
#ifdef FE_TONEAREST
    case FE_TONEAREST:
#endif
#ifdef FE_TONEARESTFROMZERO
    case FE_TONEARESTFROMZERO:
#endif
#ifdef FE_TOWARDZERO
    case FE_TOWARDZERO:
#endif
#ifdef FE_UPWARD
    case FE_UPWARD:
#endif
        return __libc_fesetround(round);
    }
    return -1;
}
