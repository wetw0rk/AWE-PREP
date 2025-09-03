/*

Extend entab and detab to accept shorthand (e.g ./entab -m +n) to mean
tab stops every n columns starting at column m. Choose convenient (for
the user) default behavior.

./detab -m 4 +n 2 -> for 4 spaces replace with 2 tabs

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  int c, temp, num_columns = 8;

  while (--argc > 0 && (*++argv)[0] == '-' || (*argv)[0] == '+')
  {
    while (c = *++argv[0])
    {
      switch(c)
      {
        case 'm':
          num_columns = atoi(*++argv), --argc;
          break;
        default:
          printf("Error: invalid command, using default config\n");
          break;
      }
    }
  }

  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      for (temp = num_columns; temp != 0; temp--)
        putchar(' ');
    else
      putchar(c);
  }

  return 0;
}
