/* SPDX-License-Identifier: CC0-1.0 */

#include "basic/cdefs.h"
#include "crt/linux/impl.h"

_LIBC_WEAK void __register_frame_info(const void *eh_frames, void *object);
_LIBC_WEAK void *__deregister_frame_info(const void *eh_frames);
_LIBC_WEAK void __cxa_finalize(void *dso_handle);

/*
 * DSO handle, unique to each shared object.
 */

_LIBC_HIDDEN void *__dso_handle =
#ifdef SHARED
    &__dso_handle;
#else
    (void *)0;
#endif

/*
 * Functions to initialize exception handler frames.
 */

__extension__ ALIGNED_SECTION(".eh_frame", void *) static void *eh_frames[0];

_LIBC_USED static void __do_init()
{
    /* Register exception handler frames. */
    if (__register_frame_info) {
        static char __object[sizeof(void *) * 8];
        __register_frame_info(eh_frames, &__object);
    }
}

_LIBC_USED static void __do_fini()
{
    /* Call global C++ destructors. */
    if (__cxa_finalize) {
        __cxa_finalize(__dso_handle);
    }

    /* Deregister exception handler frames. */
    if (__deregister_frame_info) {
        __deregister_frame_info(eh_frames);
    }
}

/*
 * Add these init/fini functions to the init/fini arrays.
 */

SECTION(".init_array") static StructorFn __init = __do_init;
SECTION(".fini_array") static StructorFn __fini = __do_fini;
