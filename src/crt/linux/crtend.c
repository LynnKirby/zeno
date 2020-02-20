/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "crt.h"
#include <stdint.h>

/* The first field of eh_frame entries is length. Zero indicates list end. */
ALIGNED_SECTION(".eh_frame", uint32_t) const unsigned eh_frames_end[] = { 0 };
