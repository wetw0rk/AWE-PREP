/*
in a two's complement number representation, our version of itoa does
not handle the largest negative number, that is, the value of n equal
to -(-2^wordsize-1). explain why not. modify it to print that value
correctly, regardless of the machine on which it runs.

Answer: because an integer can only hold values between -32768 and
32767. in order to mitigate this error we use long long which will
be able to hold -2147483648 and 2147483648 on a 32bit system for a
64bit it's -9223372036854775807 and 9223372036854775807..
*/

#include <stdio.h>

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

/* itoa: convert n to characters in a */
void itoa(long long int n, char s[])
{
    int i, sign;

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
}

int main()
{
    char s[13];

    itoa(-2147483648, s);
    printf("%s\n", s);
    
    return(0);
}
