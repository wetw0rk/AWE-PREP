/*

Boolean Type: Introduced in C99, objects declared as _Bool can store only the values 0 and 1.
If we include the header we can spell the type as bool, and use values such as true and false
to represent 1 and 0 respectively.

*/

#include <stdbool.h>

int main(void)
{
  _Bool flag1 = 0;
  bool flag2 = false; // better to use this syntax, as this is the long term direction of C
}
