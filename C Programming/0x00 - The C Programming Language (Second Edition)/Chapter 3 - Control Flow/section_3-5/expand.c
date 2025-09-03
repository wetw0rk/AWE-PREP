/*
write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into
the equivalen complete list abc...xyz in s2. Allow for letters of either case and digits and be
prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing (-)
is taken literally.
*/

#include <stdio.h>
#include <string.h>

#define MAXBUFFER 27

void expand(char s1[], char s2[])
{
    int i = 0;  /* loop counter for overall string */
    int j = 0;  /* loop counter for indexing */
    int c;      /* character checking */
    int g;      /* ^ */

    while (i < strlen(s1))
    {
        if (s1[i] == '-')
        {
            /* detect if we have the a-, A-, 0- case */
            if (s1[i-1] != '\0' && s1[i+1] == '\0')
            {
                c = s1[i-1]; 
                /* assign loop iterator for our range */
                if      (c >= 'a' && c <= 'z') { g = 'z'; }
                else if (c >= 'A' && c <= 'Z') { g = 'Z'; }
                else if (c >= '0' && c <= '9') { g = '9'; }
                s2[j++] = c;
                while (c != g)
                {
                    s2[j++] = ++c;
                }
                s2[j] = '\0'; /* null terminate the string */
                printf("%c-: %s\n", s1[i-1], s2);
            }

            /* detect if we have the -z, -Z, -9 case */
            else if (s1[i-1] == '\0' && s1[i+1] != '\0')
            {
                /* assign loop iterator for our range */
                if      (s1[i+1] >= 'A' && s1[i+1] <= 'Z') { c = 'A'; }
                else if (s1[i+1] >= 'a' && s1[i+1] <= 'z') { c = 'a'; }
                else if (s1[i+1] >= '0' && s1[i+1] <= '9') { c = '0'; }
                s2[j++] = c; /* assign first character in range */
                while (c != s1[i+1])
                {
                    s2[j++] = ++c;
                }
                s2[j] = '\0'; /* null terminate the string */
                printf("-%c: %s\n", s1[i+1], s2);
            }

            /* detect if we have the normal case e.g (A-Z, a-Z, 0-9) */
            else if (s1[i-1] >= 'A' && s1[i-1] <= 'Z' || s1[i-1] >= 'a' && s1[i-1] <= 'z' || s1[i-1] >= '0' && s1[i-1] <= '9')
            {
                c = s1[i-1]; /* assign loop iterator for our range */
                s2[j++] = c; /* assign first character in range */
                while (c != s1[i+1])
                {
                    s2[j++] = ++c;
                }
                s2[j] = '\0'; /* null terminate the string */
                printf("%c-%c: %s\n", s1[i-1], s1[i+1], s2);
            }

            j = 0; /* reset the array index 2 overwrite */
        }
        i++;
    }
}

int main()
{
    char s2[MAXBUFFER];
    char s1[]="-5A-Za-f0-4F-";


    expand(s1, s2);

    return(0);
}
