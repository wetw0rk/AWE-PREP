#include <stdio.h> 
#include <string.h>

#define qsort StandardLibraryQsortRenamedDueToConflict
#include <stdlib.h>
#undef qsort

#define ALLOCSIZE 10000    /* size of available space in buffer */
#define MAXLINE   1000     /* max line for getline */
#define MAXLINES  5000     /* max #lines to be sorted */
#define MAXLEN    1000     /* max lines to read in */

char *lineptr[MAXLINES];  /* pointers to text lines  */

static char allocbuf[ALLOCSIZE]; /* storage for alloc  */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
  if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
    allocp += n;
    return allocp -n; /* old p */
  } else
    return 0;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getline(line, MAXLEN)) > 0)
  {
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  if (left >= right)  /* do nothing if array contains */
    return;           /* fewer than two elements      */

  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1, comp);
  qsort(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

/* getline: read a line into s, return length */
int getline(char *s, int lim)
{
  char *og = s; /* the original address aka s[0] */
  int c, l;

  while ((s-og) < lim-1 && ((c = getchar()) != EOF) && c != '\n') {
    *s++ = c;
  }

  if (c == '\n') {
    *s++ = c;
  }
  *s = '\0';

  return (s-og);
}

/* sort input lines */
int main(int argc, char * argv[])
{
  int nlines;       /* number of input lines read */
  int numeric = 0;  /* 1 if numeric sort          */

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines -1,
        (int (*)(void*,void*))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}
