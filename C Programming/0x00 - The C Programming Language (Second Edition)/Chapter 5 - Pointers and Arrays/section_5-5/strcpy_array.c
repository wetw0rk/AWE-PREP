#include <stdio.h>

/* strcpy: copy t to s; array subscript version */
void strcpy(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}

int main()
{
    char str1[]= "Milton";
    char *str2= "AAAAAA";

    printf("Before: str1 = %s, *str2 = %s\n", str1, str2);
    strcpy(str1, str2);
    printf("After : str1 = %s, *str2 = %s\n", str1, str2);
}
