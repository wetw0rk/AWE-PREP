/*

As written, getint treats a + or - not followed by a digit as a valid representation of zero.
Fix it to push such a character back on the input

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

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, backup;
    *pn = 0;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? - 1: 1; /* if we have a negative/positive respectively              */
    if (c == '+' || c == '-') { /* if '+' or '-' char is detected                           */
        backup = c;             /* backup the char '+' or '-'                               */
        c = getch();            /* get another char from input                              */
        if (c == '\n') {        /* if the new char is a newline we encountered int+ or int- */
            *pn = backup;       /* set the array index to the original '-' or '+' char      */
            return 0;           /* return anything tbh                                      */
        }
    }
    
    for (*pn; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);
    return c;
}

int main()
{
    int i, n, array[BUFSIZE], getint(int *);

    for (n = 0; n < BUFSIZE && getint(&array[n]) != EOF; n++)
        ;

    printf("Printing integers (45 == -, 43 == +)\n");
    for (i = 0; i < n; i++)
    {
        printf("array[%d]= %d\n", i, array[i]);
    }

    return 0;
}
