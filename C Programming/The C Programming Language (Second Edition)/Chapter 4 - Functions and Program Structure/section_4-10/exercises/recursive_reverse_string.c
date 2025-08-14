/*

Write a recursive version of the function reverse(s), which reverses
the string s in place.

Note: borrowed concept from https://www.sanfoundry.com/c-program-reverse-string-using-recursion-2/
      only really big change is only needing to pass the string as an argument to the function.

*/

#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    char c;
    static int index;
    int size = strlen(s)-1;

    c = s[index];               /* store character ar X index in c                  */
    s[index] = s[size - index]; /* overwrite said char with the last char in string */
    s[size - index] = c;        /* place character that was saved at end of string  */

    /* reverse occurs (--><--) towards each other so once done return */
    if (index == size / 2)
    {
        return;
    }
    index++; /* load the next character */

    reverse(s); /* call the function until done */
}

int main()
{
    char s[]="abcd";

    printf("Before: %s\n", s);
    reverse(s);
    printf("After: %s\n", s);

    return 0;
}
