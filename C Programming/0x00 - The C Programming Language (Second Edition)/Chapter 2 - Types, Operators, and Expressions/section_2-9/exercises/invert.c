#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int pp, pp1, pp2, var1, var2, ans, one, two;
    
    pp1 = ((1 << p) - 1);   // (1 SHR 4)-1
    pp2 = ((1 << (p-n)) -1);    // (1 SHR 2)-1
    pp = pp1 - pp2;         // subtracting em 

    var1 = (~(x & pp)) & pp;
    var2 = x & ~(pp);
    ans = var1|var2;

    return ans;
}

int main()
{
    unsigned int a, x=192;

    a = invert(x, 5, 2);

    printf("%d\n", a);
}
