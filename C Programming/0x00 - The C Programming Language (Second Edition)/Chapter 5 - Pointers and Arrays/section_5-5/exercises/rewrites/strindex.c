/*

Rewrite appropriate programs from earlier chapters and exercises
with pointers instead of array indexing.

rewrite of: strindex.c

*/

#include <stdio.h>

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    int i, j, k;

    for (i = 0; *(s+i) != '\0'; i++) {
        for (j=i, k=0; *(t+k) != '\0' && *(s+j)==*(t+k); j++, k++)
            ;
        if (k > 0 && *(t+k) == '\0')
            return i;
    }
    return -1;
}

int main()
{
    int index;
    char str[]="Test";

    index = strindex(str, "e");

    printf("str[]=\"%s\" str[%d]= 'e'\n", str, index);
}
