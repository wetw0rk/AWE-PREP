/*

On POSIX systems, you can use the close function to deallocate the
file descriptor specified by fildes:

*/

close(int fildes);

/* An application that uses fopen to open a file must use fclose to
   close it; an application that uses open to open a file must use
   close to close it (unless it passed the descriptor to fdopen, in
   which case it must close by calling fclose).  */
