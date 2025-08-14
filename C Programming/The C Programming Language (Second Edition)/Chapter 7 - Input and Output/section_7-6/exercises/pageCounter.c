/*
 
Write a program to print a set of files, starting each one on a new page,
with a title and running page count for each file.

A: The format is as follows

<page number>       <name of file>
         <file content>
<page number2>       <name of file2>
        <file content2>

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE  50
#define MAXLINES 50

int fdread(char (*cbuff)[][MAXLINE], int max, FILE *fptr);

int main(int argc, char *argv[])
{
  FILE *fp;
  int lines, page_number = 1;
  char line_buff[MAXLINES][MAXLINE];

  if (argc == 1) {
    printf("usage: %s <file> <file>...\n", argv[0]);
    return -1;
  }
  while (--argc > 0) {
    if ((fp = fopen(*++argv, "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", *argv);
      return -1;
    }
    
    /* print the "header" */
    printf("%s\t%d\n\n", *argv, page_number++);

    /* read in the lines and print them */
    lines = fdread(&line_buff, MAXLINE, fp);
    for (int i = 0; i < lines; i++)
      printf("\t%s\n", line_buff[i]);
    putchar('\n');
  }
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
