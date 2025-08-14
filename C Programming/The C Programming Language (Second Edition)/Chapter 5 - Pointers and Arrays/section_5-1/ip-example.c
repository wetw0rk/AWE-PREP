#include <stdio.h>

int main()
{
    int x = 1, y = 2, z[10];
    int *ip;    /* ip is a pointer to int */

    ip = &x;    /* ip now points to x */
    printf("ip -> 0x%x -> x -> %d\n", ip, *ip);
    y = *ip;    /* y is now 1 */
    printf("y = *ip -> %d\n", y);
    *ip = 0;    /* x is now 0 */
    printf("*ip = 0 so x = %d\n", x);
    ip = &z[0]; /* ip now points to z[0] */
    printf("ip -> 0x%x -> z[0]\n", ip);
}
