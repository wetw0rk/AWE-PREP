/*

The strcpy_s function is a close replacement for the strcpy function defined in <string.h>.
strcpy_s copies characters from a source string to a destination chracter array up to and
including the terminating null chracter. Below is the strcpy_s signature:

*/

errno_t strcpy_s(
  char * restrict s1, rsize_t s1max, const char * restrict s2
);
