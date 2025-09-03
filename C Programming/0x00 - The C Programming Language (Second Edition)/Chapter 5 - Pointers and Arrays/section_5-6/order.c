#include <stdio.h>
#include <string.h>

#define ALLOCSIZE 10000 /* size of available space in buffer */
#define MAXLINE 1000    /* max line for getline */
#define MAXLEN 1000     /* max lines to read in */

char *lineptr[BUFSIZ]; /* pointer to test lines (BUFSIZ from stdio.h == 8192)*/

/* qsort: sort v[left] */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements  */
    swap(v, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

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

static char allocbuf[ALLOCSIZE]; /* storage for alloc  */
static char *allocp = allocbuf;  /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp -n; /* old p */
    } else /* not enough room */
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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* sort input lines */
int main()
{
    int nlines;

    if ((nlines = readlines(lineptr, BUFSIZ)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
