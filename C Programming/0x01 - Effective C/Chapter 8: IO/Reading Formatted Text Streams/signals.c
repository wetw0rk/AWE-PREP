/*

In this section we demonstrate the use of the fscanf function to read formatted
input. fscanf has the following signature:

  int fscanf(FILE * restrict stream, const char * restrict format, ...);

To demonstrate the use of fscanf, as well as some other I/O functions, we'll
implement a program that reads in the signals.txt file. Each line containing:

  - A signal number (a small, positive integer value)
  - The signal ID (a small string of up to six alphanumeric characters)
  - A short string with the description of the signal 

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int status = EXIT_SUCCESS;
  FILE *in;

  struct sigrecord {
    int signum;
    char signame[10];
    char sigdesc[100];
  } sigrec;

  if ((in = fopen("signals.txt", "r")) == NULL) {
    fputs("Cannot open signals.txt file\n", stderr);
    return EXIT_FAILURE;
  }

  do {
    /*
    %d - Matches the first optionally signed decimal integer - which should be signal number in our file
    
    %9s - Matches the next sequence of nonwhitespace chracters from the input stream - corresponding to
          the signal name - and stores this characters as a string. The length modifier prevents more
          than nine characters that have been matched. A conversion specifier of %10s in this example
          would allow a buffer overflow to occur.
    
    %*[ \t] - Reads all chracters, starting from the end of the signal ID. The purpose is to consume
              any space or horizontal tab characters between these two fields and suppress them by
              using the assignment-suppressing specifier *.

    %99[^\n] - This fancy conversion specifier will match the signal description field in the file. The
               brackets ([]) contain a "scanset", which is similiar to a regular expression. This scanset
               uses the circumflex (^) to exclude \n characters. Put together, %99[^\n] reads all the
               characters until it reaches \n (or EOF), and stores them in the fifth argument referenced
               by sigrec.sigdesc.
    */
    int n = fscanf(in, "%d%9s%*[ \t]%99[^\n]",
      &sigrec.signum, sigrec.signame, sigrec.sigdesc
    );
    if (n == 3) {
      printf(
        "Signal\n  number = %d\n  name = %s\n  description = %s\n\n",
        sigrec.signum, sigrec.signame, sigrec.sigdesc
      );
    }
    else if (n != EOF) {
      fputs("Failed to match signum, signame or sigdesc\n", stderr);
      status = EXIT_FAILURE;
      break;
    }
    else {
      break;
    }
  } while (1);

  if (fclose(in) == EOF) {
    fputs("Failed to close file\n", stderr);
    status = EXIT_FAILURE;
  }
  return status;
}
