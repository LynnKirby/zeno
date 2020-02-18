# Predefined CMake Toolchains

These toolchains should work for the most common developer setups. They assume
you have the correct tools in your `PATH`.

The `base` subdirectory contains most of the logic. The files in this directory
mostly set a few variables and then include one of the base toolchains.

The toolchain prefixes are:

- `clang` – Uses `clang` with the correct `--target=...` option. This is easy
  because Clang is natively a cross-compiler.

- `gcc-cross` – Uses `<triple>-gcc`. Requires the whole `<triple>` toolchain
  installed.

- `gcc-multilib` – Uses `gcc` with the correct options to enable the target.
  This only works when GCC is compiled as multilib. For example, GCC for x86-64
  is almost always compiled with support for i386, x86-64, and the x32 ABI.
