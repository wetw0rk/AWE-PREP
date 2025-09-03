/*
 
Rewrite the postfix calculator of Chapter 4 to use scanf and/or
sscanf to do the input and number conversion.
 
*/

#include <ctype.h>
#include <stdio.h>

int main()
{
  char c;
  int x, y, n;

  while ((n = scanf("%d %d %c", &x, &y, &c)) != EOF) {
    if (n == 3) { /* verify we had 3 matches */ 
      switch (c) {
        case '+':
          printf("\t%d\n", (x + y));
          break;
        case '*':
          printf("\t%d\n", (x * y));
          break;
        case '-':
          printf("\t%d\n", (x - y));
          break;
        case '/':
          printf("\t%d\n", (x / y));
          break;
        defualt:
          printf("error: unknown command %c\n", c);
          break;
      }
    }
  }
  return 0;
}
