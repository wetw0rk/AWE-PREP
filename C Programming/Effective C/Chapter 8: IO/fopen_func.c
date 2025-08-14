/*

The fopen function opens the file whose name is given as a string and pointed to
by a filename, and then associates a stream with it. If the file doesn't already
exist, fopen will create it.

```
FILE *fopen(
  const char * restrict filename,
  const char * restrict mode
)
```

However, opening a file with read mode (by passing r) fails if the file does not
exist or cannot be read.

*/

/* WARNING: On a final note, make sure that you never copy a FILE object. The
   following program, for example, can fail because a by-value copy of stdout
   is being used in the call to fputs: */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE my_stdout = *stdout;
  if (fputs("Hello, world!\n", &my_stdout) == EOF) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
