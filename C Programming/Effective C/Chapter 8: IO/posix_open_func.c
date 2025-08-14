/*

On POSIX systems, the open function (IEEE Std 1003.1:2018) establishes
the connection between a file identified by path and a value called a
file descriptor.

The file descriptor is a non-negative integer that refers to the structure
representing the file. The file descriptor returned by the open() function
is the smallest integer not yet returned by a preoir call to open() or passed
to close() and is unique to the calling process. The file descriptor is
used by other I/O functions to refer to that file.

The open() function sets the file offset used to mark the current position
within the file to the beginning of the file.

*/

#include <fcntlh.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

// ---snip---

int fd;
mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
const char *pathname = "/tmp/file";

// ---snip---
if ((fd = open(pathname, (O_WRONLY | O_CREAT | O_TRUNC), mode)) == -1)
{
  fprintf(stderr, "Can't open %s.\n", pathname);
  exit(1);
}
// ---snip---
