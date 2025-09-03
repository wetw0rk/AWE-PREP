/*
write a program to remove all comments from a C program. don't forget
to handle qouted strings and character constants properly. C comments
do not nest.

Usage: cat <code.c> | ./<program>
*/

#include <stdio.h>

/* this function checks for comment blocks */
int check(int c, char begin[], char end[])
{
    /* here we allocate a char to form char string */
    if (c == '/') { begin[0] = c; }
    if (c == '*') { begin[1] = c; }

    /* if we have a combination we have a block */
    if (begin[0] == '/' && begin[1] == '*') {

        if (c == '*') { end[0] = c; }
        if (c == '/') { end[1] = c; }

        /* if we are done with the block return */
        if (end[0] == '*' && end[1] == '/')
        {
            return 1;
        }
    }
    /* If we are not within a comment block */
    else if (c != '/')
    {
        return 1;
    }
}

int main()
{
    char begin[2], end[2];
    int i, c, go;

    while ((c = getchar()) != EOF)
    {
        go = check(c, begin, end);
        if (go == 1) {
            /* reset each array for checking once more */
            for (i = 0; i < 2; i++) { begin[i] = ' '; end[i] = ' '; }

            /* avoid extra */
            if (c != '/') {
                putchar(c);
            }
        }
    }
}
