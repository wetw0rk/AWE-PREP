#include <stdio.h>

/* lower: converts c to lower case: ASCII only */
int lower(int c)
{
    (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
    
    return c;
}

int main()
{
    char letter = 'B';
    printf("%c\n", lower(letter));
}
