#include <stdio.h>

void main(void) {
  int i = 0;

  printf("(should be 3) i = %d\n", (i=2, ++i));
}
