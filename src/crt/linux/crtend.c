/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "crt.h"

/* The first field of eh_frame entries is length. Zero indicates list end. */
/* FIXME: The type should be uint32_t once <stdint.h> is available. */
ALIGNED_SECTION(".eh_frame", unsigned) const unsigned eh_frames_end[] = { 0 };
