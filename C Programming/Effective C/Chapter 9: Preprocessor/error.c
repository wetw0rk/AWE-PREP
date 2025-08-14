/*

C has the #error preprocessing directive which causes the implementation to produce
a diagnostic message. You can optionally follow this directive with one or more
preprocessor tokens to include in the resulting diagnostic message.

*/

#if __STDC__ && __STDC__NO_THREADS__ != 1
#include <threads.h>
// ---snip---
#elif POSIX_THREADS == 200809L
#include <pthread.h>
//---snip---
#else
#error Neither <threads.h> nor <pthread.h> is available
#endif

void main(void) {}
