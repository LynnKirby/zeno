# Developer References

## Language and library

- ISO C working drafts
  - [C99 (final)](https://wg14.link/c99)
  - [C11 (final)](https://wg14.link/c11)
  - [C18 (final)](https://wg14.link/c18)
  - [C2x (latest)](https://wg14.link/c2x)
- ISO C++ working drafts
  - [C++11 (final)](https://timsong-cpp.github.io/cppwp/n3337/)
  - [C++14 (final)](https://timsong-cpp.github.io/cppwp/n4140/)
  - [C++17 (final)](https://timsong-cpp.github.io/cppwp/n4659/)
  - [C++20 (latest)](https://eel.is/c++draft/)
- [POSIX-1.2017](https://pubs.opengroup.org/onlinepubs/9699919799/)
- [Linux Standard Base 5.0.0](https://refspecs.linuxfoundation.org/lsb.shtml)

## ABI

- [System V x86-64 psABI v1.0](https://github.com/hjl-tools/x86-psABI/wiki/x86-64-psABI-1.0.pdf)
- [System V Intel386 psABI v1.1](https://github.com/hjl-tools/x86-psABI/wiki/intel386-psABI-1.1.pdf)
- [ARM ABI Documentation](https://developer.arm.com/architectures/system-architectures/software-standards/abi)
- [Itanium C++ ABI](https://itanium-cxx-abi.github.io/cxx-abi/abi.html)
- [Itanium C++ ABI: Exception Handling](https://itanium-cxx-abi.github.io/cxx-abi/abi-eh.html)

## Architectures

- [Intel® 64 and IA-32 Architectures Software Developer Manuals](https://software.intel.com/en-us/articles/intel-sdm)
  - [Volume 1: Basic Architecture](https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-software-developers-manual-volume-1-basic-architecture)
  - [Volume 2: Instruction set reference, A-Z](https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-sdm-combined-volumes-2a-2b-2c-and-2d-instruction-set-reference-a-z)
  - [Volume 3: System programming guide](https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-sdm-combined-volumes-3a-3b-3c-and-3d-system-programming-guide)
  - [Volume 4: Model-specific registers](https://software.intel.com/en-us/download/intel-64-and-ia-32-architectures-software-developers-manual-volume-4-model-specific-registers)
- WebAssembly
  - [WebAssembly Specification 1.0](https://webassembly.github.io/spec/core/index.html)
  - [WebAssembly tool conventions](https://github.com/WebAssembly/tool-conventions)

## Other library implementations

### libc

- [Bionic](https://android.googlesource.com/platform/bionic/+/master/)
  ([GitHub mirror](https://github.com/aosp-mirror/platform_bionic))
- [GNU C Library](https://sourceware.org/git/?p=glibc.git)
  ([GitHub mirror](https://github.com/bminor/glibc))
- [klibc](https://git.kernel.org/pub/scm/libs/klibc/klibc.git)
- [llvm-libc](https://github.com/llvm/llvm-project/tree/master/libc)
- [Newlib](https://sourceware.org/git/gitweb.cgi?p=newlib-cygwin.git)
- [musl](https://git.musl-libc.org/cgit/musl/)
  ([GitHub mirror](https://github.com/bminor/musl))
- [relibc](https://gitlab.redox-os.org/redox-os/relibc)
- [wasi-libc](https://github.com/CraneStation/wasi-libc/)
- BSDs. Note the code is spread through the source tree as is usual for them.
  See primarily `/include`, `/sys/sys`, `/lib/libc`, and `/lib/{libm,msun}`.
  - [FreeBSD](https://svnweb.freebsd.org/base/head/)
    ([GitHub mirror](https://github.com/freebsd/freebsd))
  - [OpenBSD](http://cvsweb.openbsd.org/cgi-bin/cvsweb/src/)
    ([GitHub mirror](https://github.com/openbsd/src))
  - [NetBSD](http://cvsweb.netbsd.org/bsdweb.cgi/src/?only_with_tag=MAIN)
    ([GitHub mirror](https://github.com/NetBSD/src))

### Compiler support

- [compiler-rt](https://github.com/llvm/llvm-project/tree/master/compiler-rt)
- [libgcc](https://gcc.gnu.org/git/gitweb.cgi?p=gcc.git;a=tree;f=libgcc;hb=HEAD)
