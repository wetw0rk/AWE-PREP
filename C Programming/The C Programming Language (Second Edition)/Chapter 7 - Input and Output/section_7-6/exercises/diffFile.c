/*

Write a program to compare two files, printing the first
line where they differ.
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE  50
#define MAXLINES 5

/* compare_lines: compare lines, if a difference is found print it, otherwise nothing */
void compare_lines(char (*lines1)[][MAXLINE], char (*lines2)[][MAXLINE], int lines)
{
  for (int i = 0; i < lines; i++)
    if ((strcmp((*lines1)[i], (*lines2)[i])) != 0)
      printf("[+] found a difference on line: %d\n\tfile1: %s\n\tfile2: %s\n",
        i,
        (*lines1)[i],
        (*lines2)[i]
      );
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

int main(int argc, char *argv[])
{
  FILE *fp;                                   /* file pointer (ofc)                                             */
  int i, r[2], fc;                            /* i == current file, r == returned lines, fc == final line count */
  char fbuff1[MAXLINES][MAXLINE];             /* used to store lines from file1                                 */
  char fbuff2[MAXLINES][MAXLINE];             /* used to store lines from file2                                 */
  char (*current_buffer)[MAXLINES][MAXLINE];  /* pointer to current file line buffer                            */

  if (argc < 3) {
    printf("Usage: %s <file1> <file2>\n", argv[0]);
    return -1;
  }

  for (i = 1; i != 3; i++)
  {
    if ((fp = fopen(argv[i], "r")) == NULL) {
      fprintf(stderr, "can't open %s\n", argv[i]);
      return -1;
    }

    /* change the buffer ptr based on file currently reading from */
    if (i == 1)
      current_buffer = &fbuff1;
    else
      current_buffer = &fbuff2;

    printf("[*] reading lines from file(%d): %s\n", i, argv[i]);
    r[i-1] = fdread(current_buffer, MAXLINE, fp);
  }

  /* only compare lines that both files contain */
  if (r[0] != r[1])
  {
    if (r[0] > r[1])
      fc = r[1];
    else
      fc = r[0];
    printf("[-] line count not equal, checking first %d lines\n", fc);
  } 
  else
    fc = r[0];

  compare_lines(&fbuff1, &fbuff2, fc);
}
