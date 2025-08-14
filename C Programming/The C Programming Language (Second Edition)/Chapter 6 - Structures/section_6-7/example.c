/*
example of typedef usage 
*/

#include <stdio.h>

int main()
{
  typedef int Number;
  typedef char * String;

  String str = "hello world";
  Number num = 1;

  printf("str: %s\n", str);
  printf("num: %d\n", num);

  return 0;
}
