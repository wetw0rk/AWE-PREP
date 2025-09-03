#include <stdio.h>

/* strcpy: copy t to s; pointer version 1 */
void strcpy(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

int main()
{
    char str1[]= "Milton";
    char *str2= "AAAAAA";

    printf("Before: str1 = %s, *str2 = %s\n", str1, str2);
    strcpy(str1, str2);
    printf("After : str1 = %s, *str2 = %s\n", str1, str2);
}
