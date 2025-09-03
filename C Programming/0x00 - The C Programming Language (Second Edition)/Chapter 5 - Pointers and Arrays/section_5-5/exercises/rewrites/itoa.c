/*

Rewrite appropriate programs from earlier chapters and exercises
with pointers instead of array indexing.

rewrite of: itoa.c

*/

#include <stdio.h>

void reverse(char s[])
{
    int i = 0; /* loop counter for string length allocation */
    int j = 0; /* loop counter for temp array assignment */
    int l = 0; /* store original char length */

    while (s[i] != '\0') { i++; }
    char temp_array[i+1];

    for (j = 0, l = i; j < l; j++)
    {
        temp_array[j] = s[--i];
    }
    j = 0, i = 0;

    while (temp_array[j] != '\0')
    {
        s[i++] = temp_array[j++];
    }
}

/* itoa: convert n to characters in a */
void itoa(int n, char *s)
{
    char *og = s; /* save the address of the pointer start */
    int sign;

    if ((sign = n) < 0)
        n = -n;
    
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (sign < 0)
        *s++ = '-';
    
    *s = '\0';
    
    /* (s-og) == strlen() */    
    s = s - (s-og);
    reverse(s);
}

int main()
{
    char s[900];

    itoa(48, s);
    printf("%s\n", s);

    return(0);
}
