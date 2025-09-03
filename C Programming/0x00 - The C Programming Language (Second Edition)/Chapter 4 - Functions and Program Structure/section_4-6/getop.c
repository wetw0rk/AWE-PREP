/*

Answer: `static int lastc` by setting lastc == 0.

Example:

    5 5 -

    first loop:     c = getch(); return 5
    second loop:    c = getch() ignore the ' ' in while loop; return 5
    third loop:     c = getch() and lastc stores '\n'; return '-'
        main.c will perform math and push onto stack
    
    fourth loop:    c = lastc; c is not '.' or '-'; return '\n'
        main.c will pop the answer off the top of the stack and print it

*/

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    static int lastc = 0;

    if (lastc == 0)
        c = getch();
    else
    {
        c = lastc;
        lastc = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();
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
            lastc = c;
            return '-';
        }
    }

    s[i] = '\0';
    if (c != EOF)
        lastc = c;

    return NUMBER;
}
