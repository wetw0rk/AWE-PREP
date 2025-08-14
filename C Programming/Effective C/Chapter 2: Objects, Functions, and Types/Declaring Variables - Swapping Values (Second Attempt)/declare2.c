/*

In the rewritten swap function, we specify two parameters, pa and pb, and declare them both as type
pointers to int. These address copies still refer to the exact same objects, so when the values of
the objects they reference are swapped in the swap function, the contents of the original objects
declared in main are accessed and also swapped.

This approach simulates"call-by-reference" by generating object addresses, passing those by value,
and then dereferencing the copied addresses to access the original objects.

*/

#include <stdio.h>

void swap(int *, int *);

int main()
{
  int a = 21;
  int b = 17;

  printf("main: a = %d, b = %d\n", a, b);
  swap(&a, &b);
  printf("main: a = %d, b = %d\n", a, b);
  return 0;
}

void swap(int *pa, int *pb) { // pa -> a: 21    pb -> b: 17
  int t = *pa;                // t: 21
  *pa = *pb;                  // pa -> a: 17    pb -> b: 17
  *pb = t;                    // pa -> a: 17    pb -> b: 21
  return;
}
