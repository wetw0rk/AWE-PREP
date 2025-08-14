/*

Rewrite appropriate programs from earlier chapters and exercises
with pointers instead of array indexing.

rewrite of: reverse.c

*/

#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char *s)
{
    int i, j, c;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
}

int main()
{
    char str[]= "Milton";

    printf("[BEFORE] str = %s\n", str);
    reverse(str);

    printf("[AFTER ] str = %s\n", str);

    return 0;
}
