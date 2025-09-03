#include <stdio.h>

union u_tag {
  int ival;
  float fval;
  char *sval;
} u;

int main()
{
  /* store a string in the char pointer */
  u.sval = "My name is Milton";
  printf("%s\n", u.sval);

  /* ALL values are now 21; u.sval no longer contains a string */
  u.ival = 21;
  printf("My age is: %d\n", u.ival);

  return 0;
}
