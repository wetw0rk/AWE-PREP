#include <stdio.h>
#include <stdarg.h>

/* miniprintf: minimal printf with variable argument list */
void miniprintf(char *fmt, ...)
{
  va_list ap; /* points to each unnamed arg in turn */
  char *p;
  char *sval;
  int ival;
  double dval;

  va_start(ap, fmt); /* make ap point to 1st unamed arg */
  for (p = fmt; *p; p++) {
    if (*p != '%') {
      putchar(*p);
      continue;
    }
    switch(*++p) {
      case 'd':
        ival = va_arg(ap, int);
        printf("%d", ival);
        break;
      case 'f':
        dval = va_arg(ap, double);
        printf("%f", dval);
        break;
      case 's':
        for (sval = va_arg(ap, char *); *sval; sval++)
          putchar(*sval);
        break;
      default:
        putchar(*p);
        break;
    }
  }
  va_end(ap);
}

int main()
{
  char str[]= "test";

  miniprintf("hello this is a %s\n", str);

  return 0;
}
