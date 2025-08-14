/*

The debug memory allocation (dmalloc) library replaces malloc, realloc, calloc, free, and
other memory management features with routines that provide debugging facilities that you
can configure at runtime.

Installation instructions: https://dmalloc.com/docs/dmalloc.html

Dmalloc CMD's:

  dmalloc --usage : just gives manual / help with the commandline

  dmalloc -l logfile -i 100 low : This command will set the logfile name to logfile, and instruct
                                  the library to perform a check every 100 invocations, specified
                                  as the -i argument, dmalloc will check the heap less often, and
                                  your code will run faster; lower numbers are more likely to catch
                                  memory problems. The third command line enables a low number of
                                  debug features. Other options include runtime for minimal checking
                                  or medium or high for more extensive heap verification

Compile using:
  // After executing: dmalloc -l logfile -i 100 low
  gcc -DDMALLOC -DDMALLOC_FUNC_CHECK dmalloc_example.c -ocaesar -ldmalloc

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ENABLE DMALLOC TO REPORT THE FILE AND LINE NUMBERS OF CALLS THAT GENERATE PROBLEMS
#ifdef DMALLOC
#include "dmalloc.h"
#endif

void usage(char *msg) {
  fprintf(stderr, "%s", msg);
  free(msg);
  return;
}

int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 4) {
    /* the error message won't be more than 80 chars */
    char *errmsg = (char *)malloc(80);
    sprintf(
      errmsg,
      "Sorry %s, \nUsage: ceaser secret_file keys_file [output_file]\n",
      getenv("USER")
    );
    usage(errmsg);  
    free(errmsg);
    exit(EXIT_FAILURE);
  }
  // ---snip---

  exit(EXIT_SUCCESS);
}
