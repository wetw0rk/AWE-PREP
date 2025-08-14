/*
 
Write a private version of scanf analogous to minprintf from
the previous section.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int miniscanf(char *fmt, ...)
{
  va_list ap;   /* points to each unnamed arg in turn */
  char *p;
  int c=0;      /* store counter */

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%')
      continue;

    switch(*++p) {
      case 'd':
        c += scanf("%d", va_arg(ap, int *));
        break;
      case 'f':
        c += scanf("%f", va_arg(ap, double *));
        break;
      case 's':
        c += scanf("%s", va_arg(ap, char *));
        break;
      default:
        break;
    }
  }
  va_end(ap);

  return c;
}

int main()
{
  int c, args;
  char name[50];

  printf("Please your first name and age: ");
  args = miniscanf("%s %d", name, &c);

  printf("\nHi %s you are %d years old\n", name, c);
  printf("Total args: %d\n", args);
}
