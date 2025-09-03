/*

The Annex K bounds-checking interface has a gets_s function we can use to eliminate
the undefined behavior caused by the gets function.

*/

#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>

void get_y_or_n(void) {
  char response[8];
  size_t len = sizeof(response);
  puts("Continue? [y] n: ");
  gets_s(response, len);
  if (response[0] == 'n')
    exit(0);
}

void main(void) {
  get_y_or_n();
}
