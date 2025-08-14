/*

Write versions of the library functions strncpy, strncat, and
strncmp, which operate at most the first n characters of their
argument strings.

library function: strncat

*/

#include <stdio.h>
#include <string.h>

/* strcatC: copies n bytes from t to the end of s */
void strcatC(char *s, char *t, int n)
{
    int s_null = strlen(s);

    while (n-- != 0)
        s[s_null++] = *t++;
}

int main()
{
    char str1[40]="Milton";
    char str2[]=" Valencia";

    printf("[before strcat] str1 = %s, str2 = %s\n", str1, str2);
    strcatC(str1, str2, 10);

    printf("[after strcat] str1 = %s, str2 = %s\n", str1, str2);

    return 0;
}
