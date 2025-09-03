/*
write a function invert(x,p,n) that returns x with the n bits that begin at position
p inverted, leaving others unchanged
*/

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n)
{
    return (x ^ (p+1-n)) & ~(~0 << n);
}

int main()
{
    unsigned int a, x=8;

    a = invert(x, 3, 3);

    printf("%d\n", a);
}
