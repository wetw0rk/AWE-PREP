/*

Write the function strend(s, t), which returns 1 if the string
t occurs at the end of the string s, and zero otherwise.

*/

#include <stdio.h>
#include <string.h>

/* strend: checks if t occurs at end of s */
int strend(char *s, char *t)
{
    int s_end = strlen(s)-1; /* point to the last letter in str */
    int t_end = strlen(t)-1; /* point to the last letter in str */

    while (t_end >= 0) {
        if (s[s_end--] == t[t_end--])
            ;
        else
            return 0;
    }

    return 1;
}

int main()
{
    char str1[] = "Milton";
    char str2[] = "lton";
    int val;

    val = strend(str1, str2);
    if (val == 1)
        printf("[+] %s appears at the end of %s\n", str2, str1);

    return 0;
}
