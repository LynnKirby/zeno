/*
 * SPDX-License-Identifier: CC0-1.0
 *
 * Determine the compiler target through predefined macros. We use the error
 * directive to provide the information. This means all we need is to preprocess
 * and not run any code, making this technique work for cross-compilation too.
 */

/* clang-format off */
/* These heavily nested macros are easier to deal with indented, but that's not
 * our usual style. */

#if GUESS_TARGET_ARCH
    #if defined(__x86_64__) || defined(_M_X64)
        #error "cmake_ARCH=x86_64"
    #elif defined(__i386__) || defined(_M_IX86)
        #error "cmake_ARCH=i386"
    #elif defined(__wasm32__)
        #error "cmake_ARCH=wasm32"
    #else
        #error "cmake_ARCH=unknown"
    #endif
#elif GUESS_TARGET_SYS
    #if defined(__linux__)
        #error "cmake_SYS=linux"
    #elif defined(_WIN32)
        #error "cmake_SYS=windows"
    #elif defined(__wasi__)
        #error "cmake_SYS=wasi"
    #else
        #error "cmake_SYS=unknown"
    #endif
#endif
