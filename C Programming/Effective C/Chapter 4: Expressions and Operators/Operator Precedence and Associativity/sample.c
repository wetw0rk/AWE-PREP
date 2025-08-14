/* page: 63 */

#include <stdio.h>

int
main()
{
  char abc[] = "abc";
  char xyz[] = "xyz";

  char *p = abc;

  printf("%c\n", ++*p);

  p = xyz;

  printf("%c\n", *p++);

}
