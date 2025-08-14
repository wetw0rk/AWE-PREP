/*
write a version of itoa that accepts three arguments instead of
two. the third argument is a minimum field width; the converted
number must be padded with blanks on the left if necessary to
make it wide enough.
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int i = 0; /* loop counter for string length allocation */
    int j = 0; /* loop counter for temp array assignment */
    int l = 0; /* store original char length */

    while (s[i] != '\0') { i++; }
    char temp_array[i+1];

    /* store num chars in correct order */
    for (j = 0, l = i; j < l; j++)
    {
        temp_array[j] = s[--i];
    }
    temp_array[j] = '\0';
    j = 0, i = 0;

    /* overwrite backwards string with reversed string */
    while (temp_array[j] != '\0')
    {
        s[i++] = temp_array[j++];
    }
    s[i] = '\0';
}

/* itoa: convert n to characters in s and append blanks to left */
void itoa(long long int n, char s[], int padding)
{
    char temp_array[padding+1];
    int i, j, len, sign;

    if ((sign = n) < 0)
        n = -n;

    i = 0;

    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    
    s[i] = '\0';
    reverse(s);

    i = 0, j = 0;
    if ((len = strlen(s) != (padding+1)))
    {
        /* place reversed string into temp_array */
        while (s[i] != '\0')
        {
            temp_array[i++] = s[i];
        }
        temp_array[i] = '\0';

        /* fill start of s[] with our spaces */
        for (i = 0; i < (padding-1); i++)
        {
            s[i] = ' ';
        }
        /* fill the rest of the array with result */
        while (temp_array[j] != '\0')
        {
            s[i++] = temp_array[j++];
        }
        s[i] = '\0';
    }
}

int main()
{
    char s[13];

    itoa(88888, s, 4);
    printf("%s\n", s);
    
    return(0);
}

