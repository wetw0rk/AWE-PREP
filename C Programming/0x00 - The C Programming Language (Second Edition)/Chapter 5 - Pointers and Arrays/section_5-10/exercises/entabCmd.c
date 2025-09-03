/*

Extend entab and detab to accept shorthand (e.g ./entab -m +n) to mean
tab stops every n columns starting at column m. Choose convenient (for
the user) default behavior.

./entab -m 4 +n 2 -> for 4 spaces replace with 2 tabs

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
  int c;                /* for holding a character (switch, and spaces)           */
  int ns = 0;           /* starting number of spacing                             */
  int num_tabs = 1;     /* default number of tabs for X amount fo spaces          */
  int num_columns = 8;  /* default number of spaces to equate to X amount of tabs */

  while (--argc > 0 && (*++argv)[0] == '-' || (*argv)[0] == '+')
  {
    while (c = *++argv[0])
    {
      switch(c)
      { 
        /*
        since we are incrementing the pointer to argv, we
        must decrement argc to exit the loop properly 
        */
        case 'm':
          num_columns = atoi(*++argv), --argc;
          break;
        case 'n':
          num_tabs = atoi(*++argv), --argc;
          break;
        default:
          printf("Error: invalid command, using default config\n");
          break;
      }
    }
  }

  /* we now know how many spaces are needed to be replaced with a tab*/
  while ((c = getchar()) != EOF)
  {
    if (c == ' ' && ns != num_columns) {
      ns++;
      if (ns == num_columns) {
        putchar('\t');
        ns = 0;
      }
    }
    else {
      putchar(c);
    }
  }
  
  return 0;
}
