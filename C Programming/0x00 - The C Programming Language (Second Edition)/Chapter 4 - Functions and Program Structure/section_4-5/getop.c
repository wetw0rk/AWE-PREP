#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    /* this handles the negative numbers */
    if (c == '-')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
        /* if we get a minus vs a negative what follows is a newline */
        if (c == '\n')
        {
            ungetch(c); /* ungetch the newline in 4 next loop */
            return '-';
        }
    }

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}
