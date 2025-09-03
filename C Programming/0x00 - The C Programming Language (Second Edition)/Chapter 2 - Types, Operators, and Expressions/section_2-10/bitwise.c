#include <stdio.h>

int bitcount(unsigned int x)
{
    int b;

    for (b = 0; x != 0; x >>= 1 ) {
        if (x & 01)
            b++;
    }

    return b;
}

int main()
{
    int answer;

    answer = bitcount(9);

    printf("%d\n", answer);
}
