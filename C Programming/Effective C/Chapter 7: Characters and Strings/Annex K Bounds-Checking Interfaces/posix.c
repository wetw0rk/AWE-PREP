/*

POSIX also defines several string-handling functions, such as strdup and strndup (IEEE Std
1003.1:2018), that provide another set of string related API's for POSIX-compliant platforms.

These replacement functions use dynamically allocated memory to ensure that buffer overflows
don't occur, and they implement a calle allocates, caller frees model.

Each function ensures that enough memory is available (except when malloc fails). The strdup
function, for example, returns a pointer to a new string that contains a duplicate of the
argument. The returned pointer should be passed to the C Standard free function to reclaim
the storage when it's no longer needed.

*/

const char *temp = getenv("TMP");
if (temp != NULL) {
  char *tmpvar = strdup(temp);
  if (tmpvar != NULL) {
    printf("TMP = %s.\n", tmpvar);
    free(tmpvar);
  }
}
