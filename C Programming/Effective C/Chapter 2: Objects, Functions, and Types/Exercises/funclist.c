/*

Declare an array of three pointers to functions and invoke the appropriate
function based on an index value passed in as an argument.

*/

#include <stdio.h>

void print_hello(void) { printf("Hello\n"); }
void print_bye(void) { printf("Bye\n"); }
void print_msg(void) { printf("Welcome to a sample program\n"); }

int main(void)
{
  void (*ptr_array[3])(void);

  ptr_array[0] = print_hello;
  ptr_array[1] = print_msg;
  ptr_array[2] = print_bye;

  for (int i = 0; i < 3; i++)
    (*ptr_array[i])();
}
