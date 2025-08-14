#include <stdio.h>

/* lower: converts c to lower case: ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main()
{
    char letter = 'B';
    printf("%c\n", lower(letter));
}
