/*
our binary search makes two tests inside the loop, when one would
suffice (at the price of more tests outside). write a version with
only one test inside the loop and measure the difference in runtime

Example: time ./a.out
*/

#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    int ret = 0;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid]) { high = mid - 1; }
        (x > v[mid]) ? (low = mid + 1) : (ret = 1);
    }
    if (ret == 1)
        return mid;
    else
        return -1;
}

int main()
{
    int v[] = {0, 1 , 3, 4, 5, 6};
    int loc;

    loc = binsearch(9, v, 6);

    printf("v[%d]=%d\n", loc, v[loc]);
}

