/* The following function func declares the variable-length array via of size
   size as an automatic variable with block scope. */

void func(size_t size) {
  int vla[size];
  // ---snip---
}

/* The array is allocated in the stack frame and freed when the current frame
   exits - similiar to the alloca function.

   The next example replaces the call to alloca in the printerr function with
   a VLA. */

void print_error(int errnum) {
  size_t size = strerrorlen(errnum) + 1;
  char msg[size];
  if (strerror_e(msg, size, errnum) != 0) {
    fputs(msg, stderr);
  }
  else {
    fputs("unknown error", stderr);
  }
}

/* The main advantage of using VLA's instead of the alloca function is that
   the syntax matches the programmers model of how arrays with automatic
   storage duration work - that is there's no need to explicitly free the
   storage.

   WARNING: VLA's share some of the problems of the alloca function, in
   that they can attempt to make allocations that exceed the bounds of the
   stack.

   GCC Compiler Flags:
    -Wvla-larger-than=size : daignose definitions of VLA's that either exceed
                             the specified size or whose bound is not sufficiently
                             constrained.

*/
