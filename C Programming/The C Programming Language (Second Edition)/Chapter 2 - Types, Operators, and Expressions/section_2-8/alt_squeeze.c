/*
write an alternative version of squeeze(s1, s2) that deletes
each character in s1 that matches any character in string s2
*/

#include <stdio.h>

/* sstrip: deletes each char in s1 if in s2 */
void sstrip(char s1[], char s2[])
{
    int i = 0, j = 0;

    while (s1[i++] != '\0')
    {
        while (s2[j] != '\0')
        {
            /* if we have a match remove it and loop */
            if (s1[i] == s2[j++] && s2[i] != ' ') {
                s1[i] = ' ';
            }
        }
        j = 0;
    }
}

int main()
{
    char s1[] = "hhelloq))0LdD";
    char s2[] = "hellow0rLdjhgfhgf---";

    /* send it off to be "stripped" of repeats */
    printf("s1[]=%s, s2[]=%s \n", s1, s2);
    sstrip(s1, s2);
    /* print result */
    printf("s1[]=%s\n", s1);

    return(0);
}
