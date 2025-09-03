#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
  char *og = s;
  int c, l;

  while ((s-og) < lim-1 && ((c = getchar()) != EOF) && c != '\n')
    *s++ = c;

  if (c == '\n')
    *s++ = c;
  *s = '\0';

  return (s-og);
}

/* find: print lines that match pattern from 1st arg */
int main(int argc, char * argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
        case 'x':
          except = 1;
          break;
        case 'n':
          number = 1;
          break;
        defualt:
          printf("find: illegal option %c\n", c);
          argc = 0;
          found = -1;
          break;
      }
  if (argc != 1)
    printf("Usage: find -x -n pattern\n");
  else
    while (getline(line, MAXLINE) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) {
        if (number)
          printf("%1d:", lineno);
        printf("%s", line);
        found++;
      }
    }

  return found;
}
