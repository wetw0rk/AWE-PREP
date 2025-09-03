/* page 14 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  size_t size = 12;
  printf("%zu\n", size); // prints 12
  (void)sizeof(int[size++]);
  printf("%zu\n", size); // prints 13
  typedef int foo[size++];
  printf("%zu\n", size); // prints 14
}
