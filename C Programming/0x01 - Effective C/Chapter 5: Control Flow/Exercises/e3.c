/*

Exercise 3:

  Fix the remaining bug in the absolute_value function in Listing 5-14.

*/

#include <stdio.h>
#include <stdlib.h>

int absolute_value(int a) {
  return abs(a);
}

int main()
{
  printf("Test: %d\n", absolute_value(6));
}
