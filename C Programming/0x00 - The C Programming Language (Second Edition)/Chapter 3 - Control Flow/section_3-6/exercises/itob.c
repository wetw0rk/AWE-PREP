/*
write the function itob(n,s,b) that converts the integer n into a base
b character representation in the string s. in particular itob(n,s,16)
formats n as a hexadecimal integer in s.
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

/* convert integer to hexadecimal */
char reval(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

/* itob: convert n to characters in base b*/
void itob(int n, char s[], int b)
{
    int i;

    /*
    input number is given base by repeatedly
    dividing it by base and taking remainder
    */
    while (n > 0) 
    {
        s[i++] = reval(n % b);
        n /= b;
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[50];

    itob(598, s, 16);

    printf("%s\n", s);
    return(0);
}
