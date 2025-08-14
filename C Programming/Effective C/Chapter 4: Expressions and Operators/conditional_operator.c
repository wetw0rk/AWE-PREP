#include <stdio.h>

int check(int num) {
  return 1 ? (num >= 0) : -1;
}

void main() {

  int x = 0;

  if ((check(x)) == 1) {
    printf("Returned 1 since, num == 0\n");
  }
}
