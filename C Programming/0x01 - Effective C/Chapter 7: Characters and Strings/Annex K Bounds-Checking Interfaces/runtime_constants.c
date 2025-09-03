/*

Runtime constraints are violations of a function requirements that the function
will detect and diagnose by a call to a handler. If this handler returns, the
functions will return a failure indicator to the caller

*/

#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#ifdef __STDC_WANT_LIB_EXT1__
  char dst[2];
  set_constraint_handler_s(ignore_handler_s);
  int r = strcpy_s(dst, sizeof(dst), "Too long!");
  print("dst = \"%s\", r = %d\n", dst, r);
  constraint_handler_t test = set_constraint_handler_s(abort_handler_s);
  r = strcpy_s(dst, sizeof(dst), "Too long!");
  print("dst = \"%s\", r = %d\n", dst, r);
#endif
}

/*

Possible output:

dst = "", r = 22
abort_handler_s was called in response to a runtime-constraint violation.
 
The runtime-constraint violation was caused by the following expression in strcpy_s:
(s1max <= (s2_len=strnlen_s(s2, s1max)) ) (in string_s.c:62)
 
Note to end users: This program was terminated as a result
of a bug present in the software. Please reach out to your
software's vendor to get more help.
Aborted

*/
