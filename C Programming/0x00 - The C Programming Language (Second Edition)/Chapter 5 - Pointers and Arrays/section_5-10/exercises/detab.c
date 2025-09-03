/*

Modify the programs entab and detab (written as exercises in
Chapter 1) to accept a list of tab stops as arguments. Use a
default tab setting if there is no argument.

Run:
  ./entab <string> <number of tabs> | ./detab <number of spaces to convert a tab into>

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int tab_length, temp, c;

  if (argc < 2)
    tab_length = 4;
  else
    tab_length = atoi(argv[1]); /* number of spaces per tab */

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      temp = tab_length;
      while (temp-- != 0)
      {
        putchar(' ');
      }
    }
    else
      putchar(c);
  }

  return(0);
}

