#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

int main()
{
  struct point pt;
  struct point maxpt = { 320, 200 };

  printf("maxpt.x: %d, maxpt.y: %d\n", maxpt.x, maxpt.y);

  pt.x = 0x10;
  pt.y = 65;

  printf("pt.x: %d, pt.y: %c\n", pt.x, pt.y);
}
