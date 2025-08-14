/*

Opening a file allocates resources. If you continually open files without
closing them, you'll eventually run out of file descriptors of handles
available for your process and attempting to open more files will fail.
Consewuently, it's important to close files after you've finished using
them.

The C standard library fclose() function closes the file:

*/

fclose(FILE *stream);
