/*

Write versions of the library functions strncpy, strncat, and
strncmp, which operate at most the first n characters of their
argument strings.

library function: strncpy

*/

#include <stdio.h>

/* strncpy: copies at most n bytes from t to s*/
void strcpy(char *s, char *t, int n)
{
    while (n-- != 0)
        *s++ = *t++;
}

int main()
{
    char str1[]= "Milton";
    char *str2= "AAA";

    printf("Before: str1 = %s, *str2 = %s\n", str1, str2);
    strcpy(str1, str2, 4); // account for null byte
    printf("After : str1 = %s, *str2 = %s\n", str1, str2);
}
