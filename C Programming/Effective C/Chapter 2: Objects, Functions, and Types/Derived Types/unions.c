/*

Union types are similiar to structures, except that the memory used by the
member object overlaps. Unions can contain an object of one type at one time,
and an object of different type at a different time, but never both objects at
the same time, and are primarily used to save memory

*/

#include <stdio.h>

union {
  struct {
    int type;
  } n;
  struct {
    int type;
    int intnode;
  } ni;
  struct {
    int type;
    double doublenode;
  } nf;
} u;

union {
  int num;
  char c;
} u2;

int main()
{
  u.nf.type = 1;
  u.nf.doublenode = 3.14;

  u2.num = 65;

  printf("u2 number: %d\n", u2.num);
  printf("u2 character: %c\n", u2.c);
}
