/*

Write the program tail, which prints the last n lines of its input. By default,
n is 10, let us say, but it can be changed by an optional argument, so that
  
  tail -n

prints the lats n lines. The program should behave rationally no matter how
unreasonable the input or the value of n. Write the program so it makes the
best use of available storage; lines should be stored as in the sorting
program of Section 5.6, not in a two dimensional array of fixed size.

*/

#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000
#define MAXLINE 1000
#define MAXLEN 1000

char *lineptr[BUFSIZ];

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
  char *og = s;
  int c, l;

  while ((s-og) < lim-1 && ((c = getchar()) != EOF) && c != '\n') {
    *s++ = c;
  }

  if (c == '\n') {
    *s++ = c;
  }

  return (s-og);
}

/* readlines: read input lines */
int readlines(char * lineptr[], int maxlines, char buffer[])
{
  int total_len, len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines || len >= (ALLOCSIZE - total_len))
      return -1;
    else
    {
      total_len += len;
      line[len-1] = '\0';
      strcpy(buffer, line);
      lineptr[nlines++] = buffer;
      buffer += total_len;
    }
  }
  return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int plines)
{
  int i;

  if (nlines < plines)
    i = 0;
  else
    i = nlines - plines;

  for (i; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

int main(int argc, char * argv[])
{
  int c;
  int nlines = 0;
  int plines = 10;
  char buffer[ALLOCSIZE];

  if (argc > 1 && (*++argv)[0] == '-')
  {
    c = *++argv[0];
    switch(c)
    {
      case 'n':
        plines = atoi(*++argv);
        break;
      default:
        printf("Error: invalid command, using default config\n");
        break;
    }
  }

  nlines += readlines(lineptr, BUFSIZ, buffer);
  writelines(lineptr, nlines, plines);
}
