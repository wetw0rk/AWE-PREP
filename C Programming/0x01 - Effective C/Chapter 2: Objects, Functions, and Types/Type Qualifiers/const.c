/*

Objects declared with the const qualifier are not modifiable. This means objects
with with const types can be placed in read-only memory by the compiler.

*/

#include <stdio.h>

void runtime_error_example()
{
  const int i = 1;
  i = 9; // error: i is const type
}

/* convince_compiler:
     It's possible to accidentally convince the compiler to change a
     const object... May appear to run but sometimes may be read-only
     causing the same runtime error as before!
*/
void convince_compiler()
{
  const int i = 1; // const object type
  
  printf("[*] const int i = %d\n", i);

  int *ip = (int *)&i; 
  *ip = 2; // undefined behavior

  printf("[*] const int i = %d\n", i);
}

/* const_mod: Another example of compilation and error (sometimes) */
void const_mod()
{
  int i = 12;
  const int j = 12;
  const int *ip = &i;
  const int *jp = &j;
  *(int *)ip = 42; // ok
  *(int *)jp = 42; // undefined behavior
}

int main()
{
  convince_compiler();
  const_mod();
}
