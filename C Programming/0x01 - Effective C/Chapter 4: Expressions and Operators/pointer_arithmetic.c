#include <stdio.h>

int main()
{
  int arr[100];
  int *arrp1 = arr[40];
  int *arrp2 = arrp1 + 20;      // arrp2 points to arr[60]
  printf("%td\n", arrp2-arrp1); // prints 20
}
