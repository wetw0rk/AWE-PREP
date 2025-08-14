/*

The newer fgetpos and fsetpos functions use the fpos_t type to represent offsets.
This type can represent arbitrarily large offsets, meaning you can use fgetpos
and fsetpos with arbitrarily large files.

A wide-oriented stream has an associated mbstate_t object that stores the streams
current parse state. A successful call to fgetpos stores this multibyte state
information as part of the value of the fpos_t object.

Other Function:

  void rewind(FILE *stream); : sets the file position indicator to the start of file

*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *fp = fopen("fred.txt", "w+");
  if (fp == NULL) {
    fputs("Cannot open fred.txt file\n", stderr);
    return EXIT_FAILURE;
  }

  fpos_t pos;
  if (fgetpos(fp, &pos) != 0) {
    perror("get position");
    return EXIT_FAILURE;
  } 

  if (fputs("abcdefghijklmnopqrstuvwxyz", fp) == EOF) {
    fputs("Cannot write to fred.txt file\n", stderr);
  }

  if (fsetpos(fp, &pos) != 0) {
    perror("set position");
    return EXIT_FAILURE;
  }

  long int fpi = ftell(fp);
  if (fpi == -1L) {
    perror("seek");
    return EXIT_FAILURE;
  }

  printf("file position = %ld\n", fpi);
  if (fputs("0123456789", fp) == EOF)
    fputs("Cannot write to fred.txt file\n", stderr);

  if (fclose(fp) == EOF) {
    fputs("Failed to close file\n", stderr);
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
