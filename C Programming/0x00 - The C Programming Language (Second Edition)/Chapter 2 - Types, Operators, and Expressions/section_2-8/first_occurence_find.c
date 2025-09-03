/*
write the function any(s1,s2), which returns the first location in the string s1
where any character from the string s2 occurs, or -1 if s1 contains no character
from s2. (strpbrk does the same job but returns a pointer to the location)
*/

#include <stdio.h>

/* any: returns the first location if char match from s2 in s1 */
int any(char s1[], char s2[])
{
    int i = 0, j = 0;

    while (s1[i++] != '\0')
    {
        while (s2[j] != '\0')
        {
            /* if an occurance is found return index */
            if (s1[i] == s2[j++])
                return i;
        }
        j = 0;
    }
    /* nothing found return -1 */
    return -1;
}

int main()
{
    char s1[]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char s2[]= "iiiiiiI";
    int a;

    a = any(s1, s2);

    printf("s1[%d]=%c from s2\n", a, s1[a]);

    return(0);
}
