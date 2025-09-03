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
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[900];

    itoa(48, s);
    printf("%s\n", s);

    return(0);
}
