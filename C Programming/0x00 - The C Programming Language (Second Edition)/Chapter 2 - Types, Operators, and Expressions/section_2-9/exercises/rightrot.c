/*
write a function rightrot(x,n) that returns the value of the
integer x rotated to the right by n bit positions
*/

#include <stdio.h>

/* ROR = (X SHR N) OR (X SHL (32-N)) where n is number of bits */
unsigned int ror(unsigned int x, unsigned int n)
{
    /* %32 needed so you don't left shift more than int width */
    return (x >> n | x << (32-n) % 32);
}

int main()
{
    unsigned int answer;

    answer = ror(6, 1);

    printf("%u\n", answer);

    return(0);
}
