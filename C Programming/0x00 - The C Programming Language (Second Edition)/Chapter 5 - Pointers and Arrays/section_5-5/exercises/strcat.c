/*

Write a pointer version of the function strcat that we showed
in Chapter 2:strcat(s,t) copies the string t to the end of s.

*/

#include <stdio.h>
#include <string.h>

/* strcat: copies the string t to the end of s */
void strcatC(char *s, char *t)
{
    int s_null = strlen(s);

    while (*t != '\0')
        s[s_null++] = *t++;
}

int main()
{
    char str1[40]="Milton";
    char str2[]=" Valencia";

    printf("[before strcat] str1 = %s, str2 = %s\n", str1, str2);
    strcatC(str1, str2);

    printf("[after strcat] str1 = %s, str2 = %s\n", str1, str2);

    return 0;
}
