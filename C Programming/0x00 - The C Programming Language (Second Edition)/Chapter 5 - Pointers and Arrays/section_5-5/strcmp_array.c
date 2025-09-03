#include <stdio.h>

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t)
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int main()
{
    int val;
    char *str1="Milton";
    char *str2="Milton";

    val = strcmp(str1, str2);
    if (val == 0)
        printf("str1 == str2\n");
    
    return 0;
}
