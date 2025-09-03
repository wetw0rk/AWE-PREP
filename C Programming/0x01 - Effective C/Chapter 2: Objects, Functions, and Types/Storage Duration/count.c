/*

The lifetime of counter is the entire execution of the program, and it will
retain its last-stored value throughout its lifetime. Outputs 1 2 3 4 5.

*/

#include <stdio.h>

void increment(void) {
  static unsigned int counter = 0;
  counter++;
  printf("%d ", counter);
}

int main(void) {
  for (int i = 0; i < 5; i++)
    increment();
  putchar('\n');
  return 0;
}
