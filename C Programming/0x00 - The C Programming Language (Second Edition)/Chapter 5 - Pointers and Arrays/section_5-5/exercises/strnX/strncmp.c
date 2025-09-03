/*

Write versions of the library functions strncpy, strncat, and
strncmp, which operate at most the first n characters of their
argument strings.

library function: strncmp

*/

#include <stdio.h>

/* strncmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strncmp(char *s, char *t, int n)
{
    for (n; *s == *t; s++, t++, n--)
        if (n == 0)
            return 0;

    return *s - *t;
}

int main()
{
    int val;
    char *str1="Milton";
    char *str2="Milo";

    val = strncmp(str1, str2, 2);
    if (val == 0)
        printf("str1 == str2\n");
    else
        printf("val=%d\n", val);
    
    return 0;
}
