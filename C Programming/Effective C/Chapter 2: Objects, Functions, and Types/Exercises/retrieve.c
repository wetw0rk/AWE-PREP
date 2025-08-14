/*

Add a retrieve function to the counting example from Listing 2-6 (page 19-20) to
retrieve the current value of counter.

*/

#include <stdio.h>

void retrieve(unsigned int counter) {
  printf("%d ", counter);
}

void increment(void) {
  static unsigned int counter = 0;
  counter++;
  retrieve(counter);
}

int main(void)
{
  for (int i = 0; i < 5; i++)
    increment();
  putchar('\n');
  return 0;
}
