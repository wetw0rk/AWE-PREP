/*
 
Write a program that will print arbitrary input in a sensible way.
At a minimum, it should print non-graphic chraracters in octal or
hexadecimal according to local custom, and break long text lines.

*/

#include <ctype.h>
#include <stdio.h>

#define MAXLINE 50

int main()
{
  int c;
  int counter = 0;

  while ((c = getchar()) != EOF) {
    printf("\\%03o", c, counter++);
    if (c == '\n' || counter == MAXLINE) {
      counter = 0;
      putchar('\n');
    }
  }
}
