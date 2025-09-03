/*
write the function htoi(s), which converts a string of
hexadecimal digits (including an optional 0x or 0X) in
to it's equivalent integer value. the allowable digits
are 0 through , a through f, and A through F.
*/

#include <math.h>
#include <stdio.h>

int htoi(unsigned char s[])
{
    int num, i, j = 0;
    int hex;

    if (s[0] == '0' && s[1] == 'x' || s[1] == 'X')
    {
        s[1] = '\0'; /* overwrite the 'x' with a null (will be used later) */
        i += 2;      /* adjust i to get index for reversing the char array */
    }

    /* read in char string until 0x00 byte (we now can reverse) */
    while (s[i] != '\0')
    {
        i++;
    }
    i--;
    /* we can now manipulate the string backwards */
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9') { hex = s[i]-'0';    } /* ASCII int to int       */
        if (s[i] >= 'A' && s[i] <= 'F') { hex = s[i]-'A'+10; } /* ASCII capitol to int   */
        if (s[i] >= 'a' && s[i] <= 'f') { hex = s[i]-'a'+10; } /* ASCII lowercase to int */

        /* answer = 0x-- * 16 ^ X */
        num += hex * pow(16,j);
        i--;
        j++;
    }

    /* if needed restore string */
    if (s[1] == '\0')
        s[1] = 'x';

    return num;
}

int main()
{
    unsigned char s[] = "0xDEAD";
    int result;

    result = htoi(s);

    printf("%s = %d\n", s, result);

    return(0);
}
