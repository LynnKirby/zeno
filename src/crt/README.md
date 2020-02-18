# `crt`

These are the bits that always get statically linked with programs. In general
they do minimal initialization and then hand-off executation to the routines in
the main libc (see the `src/initfini` directory).

## Linux

Output files:

- `crti.o` and `crtn.o` provides support for initialization/finalization using
  `.init` and `.fini` sections. Each section contains a single function called
  `_init()` or `_fini()` as a rule. These object files are the start and end of
  those functions. Rather than generating an entire function itself, the
  compiler assumes we know what we're doing and just places its machine code
  directly between them to make the functions.

- `crtbegin.o` and `crtend.o` also form a sandwich with user code in the middle.
  On startup they register exception frames stored in the binary which are used
  for debugging. On exit (either the whole program exits or the shared object is
  unloaded) they unregister the binary's exception frames and call global C++
  destructors.

  Often these files also handle the other old-style initialization/finalization
  which uses the `.ctors` and `.dtors` section. Currently supported targets
  don't use them so support has not been added.

- `crt1.o` provides the `_start` function which is where an executable first
  begins running. The Linux kernel places information on the stack about the
  process (things like `argv` and `argc`) which we need to locate and then
  pass on to the main initialization routine in the libc.
