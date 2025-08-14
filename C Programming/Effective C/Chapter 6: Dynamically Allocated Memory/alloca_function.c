/*

For performance reasons, the alloca functions, supported by some implementations,
allow for dynamic allocation at runtime from the stack rather than the heap. The
example below shows an eample called printerr that uses alloca() to allocate storage
for an error string before printing to stderr.

WARNING: THE USE OF ALLOCA IS DISCOURAGED

WHY:
  - alloca can make allocations that exceeds the bounds of the stack (DOES NOT RET NULL SO CANT CHECK FOR THIS)
  - alloca SHOULD NOT BE free'd like calls using malloc


GCC Compiler Flags:
  -Walloca : daignoses all calls to the alloca function
  -Walloca-larger-than=<size> : daignoses any call to alloca when the requested memory is more than size

*/

void printerr(errno_t errnum) {
  rsize_t size = strerrorlen_s(errnum) + 1;
  char *msg = (char *)alloca(size);
  if (strerror_s(msg, size, errnum) != 0) {
    fputs(msg, stderr);
  }
  else {
    fputs("uknown error", stderr);
  }
}
