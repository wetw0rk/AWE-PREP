#include <stdio.h>

/* strlen: return length of string s */
int strlen(char *s)
{
    char *p = s;

    while (*p != '\0')
        p++;

    printf("p = 0x%x, s = 0x%x\n", p, s);
    return p-s;
}

int main()
{
    char str[]= "AAAAAAAAA";

    printf("Length: %d\n", strlen(str));
}
