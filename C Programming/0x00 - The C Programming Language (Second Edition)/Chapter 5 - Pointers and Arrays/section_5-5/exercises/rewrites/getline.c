/*

Rewrite appropriate programs from earlier chapters and exercises
with pointers instead of array indexing.

rewrite of: getline.c

*/

#include <stdio.h>

#define MAXLINE 1000

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

int main()
{
    char str[MAXLINE];
    int val;

    while ((val = getline(str, MAXLINE)) > 0)
        printf("val = %d, str = %s\n", val, str);

    return 0;
}
