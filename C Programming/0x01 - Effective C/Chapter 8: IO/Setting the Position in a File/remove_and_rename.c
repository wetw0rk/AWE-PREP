/*

The C Standard Library provides a remove function to delete a file, and a rename
function to move or rename it.

*/

int remove(const char *filename);
int rename(const char *old, const char *new);

/* In POSIX, the file deletion function is named unlink: */

int unlink(const char *path);
