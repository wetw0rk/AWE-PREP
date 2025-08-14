#include <stdio.h>

unsigned int getbits(unsigned int x, int p, int n)
{
    unsigned int one, two;

    // 9 = 0000 1001
    one = x >> (p+1-n); // x SHR (number evaluated) - e.g 9 SHR (4+1-3)               = 0000 0010
    two = ~(~0 << n);   // NOT(NOT 0 << number)     - e.g NOT(NOT 0 << 3)             = 0000 0111
    x=one&two;          // x AND y                  - e.g 2(00000010) AND 7(00000111) = 0000 0010 

    return x;


//    return (x >> (p+1-n)) & ~(~0 << n);
}

int main()
{
    unsigned int a, x=9;

    a = getbits(x, 4, 3);

    printf("%d\n", a);
}
