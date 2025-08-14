#include <stdio.h>
#include <unistd.h>

/* getchar: unbuffered single character input */
int getchar(void)
{
  char c;

  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int main()
{
  int ch;

  while ((ch = getchar()) != EOF)
    putchar(ch);
}
