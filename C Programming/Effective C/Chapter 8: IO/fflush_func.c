/*

As described earlier in this chapter, streams can be fully or partially buffered,
meaning that data you thought you wrote may not yet be delivered

The fflush function delivers any unwritten data for a specified stream to the host
enviroment to be written to the file:

*/

int fflush(FILE *stream);

/* The behavior is undefined if the last operation on the stream was input. If
   the stream is a null pointer, the fflush function performs this flushing
   action on all streams. You should makre sure that your file pointer isn't
   null before calling fflush if this isn't your intent. The fflush functoin
   sets the error indicator for the stream and returns EOF if a write error
   occirs; otherwise, it returns 0. */
