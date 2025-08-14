/*

Rewrite the program cat from Chapter 7 using read, write, open and
close instead of their standard library equivalents.
 
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/* cat: concatenate files */
int main(int argc, char *argv[])
{
  int fd;
  void filecopy(int, int);

  if (argc == 1)
    filecopy(STDIN_FILENO, STDOUT_FILENO);
  else
    while (--argc > 0)
      if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
        write(STDERR_FILENO, "can't open file\n", 16);
        return -1;
      } else {
        filecopy(fd, STDOUT_FILENO);
        close(fd);
      }

  return 0;
}

/* filecopy: copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
  int n;
  char buf[BUFSIZ];

  while ((n = read(ifd, buf, BUFSIZ)) > 0)
    write(ofd, buf, n);
}
