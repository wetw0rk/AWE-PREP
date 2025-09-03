#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int v[] = {0, 1 , 3, 4, 5, 6};
    int loc;

    loc = binsearch(4, v, 9);

    printf("v[%d]=%d\n", loc, v[loc]);
}
