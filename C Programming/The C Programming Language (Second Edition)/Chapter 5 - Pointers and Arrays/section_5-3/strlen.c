#include <stdio.h>
#undef strlen

/* strlen: return length of string s */
int strlen(char *s)
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    
    return n;
}

int main()
{
    char array[]="ABCDEFG";
    char *ptr = "ABC";

    printf("%d\n", strlen("hello world"));  /* string constant */
    printf("%d\n", strlen(array));          /* char array[];   */
    printf("%d\n", strlen(ptr));            /* char *ptr;      */

    printf("*ptr   = %c\n", *ptr);
    printf("*ptr+1 = %c\n", *ptr+1);
}
