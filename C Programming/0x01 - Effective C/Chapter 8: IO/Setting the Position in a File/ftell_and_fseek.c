/*

The ftell() function obtains the current value of the file position indicator,
while the fseek function sets the file position indicator. These functions use
the long int type to represent offsets (positions) in a file and are therefore
limited to offsets that can be represented as a long int.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp = fopen("fred.txt", "r");

  if (fp == NULL) {
    fputs("Cannot open fred.txt file\n", stderr);
    return EXIT_FAILURE;
  }

  if (fseek(fp, 0, SEEK_END) != 0) {
    fputs("Seek to end of file failed\n", stderr);
    return EXIT_FAILURE;
  }

  long int fpi = ftell(fp);
  if (fpi == -1L) {
    perror("Tell");
    return EXIT_FAILURE;
  }

  printf("file position = %1d\n", fpi);
  if (fclose(fp) == EOF) {
    fputs("Failed to close file\n", stderr);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
