/*

A pointer type is derived from the function or object type that it points to, called
the referenced type.

You use the (&) address operator to take the address of an object or function and the
indirection operator (*) to resolve to the object.

*/

#include <stdio.h>

int main(void)
{
  int *ip; /* pointer to an int */
  char *cp; /* pointer to a char */
  void *vp; /* pointer to a void */

  int i = 17;
  ip = &i;
  printf("ip now contains: %d\n", *ip);

  /* we can also use the & operator on the result of the * operator */
  ip = &*ip;
  printf("ip now contains: %d\n", *ip);

}
