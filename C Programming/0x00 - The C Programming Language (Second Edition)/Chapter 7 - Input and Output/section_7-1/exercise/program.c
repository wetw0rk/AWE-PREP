/*

Write a program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with, as found in argv[0]

Compile using:
  gcc program.c -o upper
  gcc program.c -o lower

*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (argv[0][0] == 'u' || argv[0][2] == 'u')
      putchar(toupper(c));
    else
      putchar(tolower(c));
  }
  putchar('\n');

  return 0;
}
