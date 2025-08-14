#include <stdio.h>

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}

int main()
{
    int val;
    char *str1="Milton";
    char *str2="Miloon";

    val = strcmp(str1, str2);
    if (val == 0)
        printf("str1 == str2\n");
    
    return 0;
}
