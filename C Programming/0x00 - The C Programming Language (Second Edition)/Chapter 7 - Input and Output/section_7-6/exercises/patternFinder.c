/*

Modify the pattern finding program of Chapter 5 to take its input
from a set of named files or, if no files are named as arguments,
from the standard input. Should the file name be printed when a 
line is found?

compile:
  gcc patternFinder.c -o find -ansi

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE  50
#define MAXLINES 5

int fdread(char (*cbuff)[][MAXLINE], int max, FILE *fptr);
int getline(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char * argv[])
{
  FILE *fp;
  int c, j, i, lines = 0;
  int except = 0, number = 0, found = 0;

  char line_buff[MAXLINES][MAXLINE];

  while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c) {
        case 'x': /* if found exclude it */
          except = 1;
          break;
        case 'n': /* print number line */
          number = 1;
          break;
        defualt:
          printf("find: illegal option %c\n", c);
          argc = 0;
          found = -1;
          break;
      }

  /* loop over every file, read in lines, and checl line for string */
  if (argc > 1)
  {
    for (i = 1; i < argc; i++)
    {
      if ((fp = fopen(argv[i], "r")) == NULL) {
        fprintf(stderr, "can't open %s\n", argv[i]);
        return -1;
      }

      /* read in lines and return line count */
      lines = fdread(&line_buff, MAXLINE, fp);

      /* print the lines depending on cli args*/
      for (j = 0; j < lines; j++)
      {
        if ((strstr(line_buff[j], argv[0]) != NULL) != except) {
          if (number)
            printf("%s:%d: %s\n", argv[i], (j+1), line_buff[j]);
          found++;
        }
      }
    }
  }
  else if (argc == 1) 
    while (getline(line_buff[0], MAXLINE) > 0) {
      lines++;
      if ((strstr(line_buff[j], argv[0]) != NULL) != except) {
        if (number)
          printf("%s:%d: %s", argv[i], lines, line_buff[j]);
        found++;
      }
    }
  else
    printf("Usage: find -x -n pattern\n");
}

/* getline: read a line into s, return length */
int getline(char *line, int max)
{
  if (fgets(line, max, stdin) == NULL)
    return 0;
  else
    return strlen(line);
}

/* fdread: readlines from a file and store them into a list */
int fdread(char (*cbuff)[][MAXLINE], int max, FILE *fptr)
{
  int c;
  int i;
  int current_line = 0;

  /* infinite loop, and initialize index at 0 */
  i = 0;
  while (1)
  {
    /* break when if we have read MAXLINES */
    if (current_line == MAXLINES)
      break;

    /* break when fptr == EOF */
    if ((c = getc(fptr)) != EOF)
    {
      (*cbuff)[current_line][i++] = c;
    }
    else
      break;

    /* if newline or at maxline inc line count */
    if (c == '\n' || i == (max-1))
      (*cbuff)[current_line++][--i] = '\0', i = 0;
  }
  fclose(fptr);

  return current_line;
}
