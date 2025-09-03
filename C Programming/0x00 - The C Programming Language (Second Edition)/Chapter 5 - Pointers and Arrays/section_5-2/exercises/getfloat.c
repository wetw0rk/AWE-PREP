/*

Write getfloat, the floating-point analog of getint. What type
does getfloat return as it's function value?

A: returns an int so that the caller knows we reached EOF
 
*/

#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push a character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
    float c, sign;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? - 1: 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    int i, n, getfloat(float *); 
    float array[BUFSIZE];

    for (n = 0; n < BUFSIZE && getfloat(&array[n]) != EOF; n++)
        ;

    printf("printing floats\n");
    for (i = 0; i < n; i++)
        printf("%.2f\n", array[i]);

    return 0;
}
