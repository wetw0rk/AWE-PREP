/*

Modify the programs entab and detab (written as exercises in
Chapter 1) to accept a list of tab stops as arguments. Use a
default tab setting if there is no argument.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  int num_tabs;

  if (argc < 2) {
    printf("%s <string> <number of tabs>\n", argv[0]);
    exit(-1);
  }

  /* if we don't have argv[2], set num_tabs to 1 */
  if (argc != 3)
    num_tabs = 1;
  else
    num_tabs = atoi(argv[2]);

  while (num_tabs-- != 0)
    putchar('\t');

  printf("%s\n", argv[1]);

  return(0);
}
