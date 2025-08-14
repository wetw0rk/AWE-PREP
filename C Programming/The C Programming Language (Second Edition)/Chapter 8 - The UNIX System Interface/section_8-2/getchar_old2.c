#include <stdio.h>
#include <unistd.h>

/* getchar: simple buffered version */
int getchar(void)
{
  static char buf[BUFSIZ];
  static char *bufp = buf;
  static int n = 0;

  if (n == 0) {
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main()
{
  int ch;

  while ((ch = getchar()) != EOF)
    putchar(ch);
}
