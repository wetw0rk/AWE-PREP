/*

First attempt to implement the swap function. This fails becuase C is a "call-by-value" langauge meaning
we provide args to a function, the value of that arg is copied into a distinct variable for use within
the function.

When the values of the parameters in the function are changed, the values in the caller are unaffected
because they are distinct objects. Consequently, the variables a and b retain their original values.

*/

#include <stdio.h>

void swap(int, int);

int main()
{
  int a = 21;
  int b = 17;

  swap(a, b);
  printf("main: a = %d, b = %d\n", a, b);
  return 0;
}

void swap(int a, int b)
{
  int t = a;
  a = b;
  b = t;

  printf("swap: a = %d, b = %d\n", a, b);
}
