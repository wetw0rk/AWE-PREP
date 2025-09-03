#if __STDC__ && __STDC_NO_THREADS__ != 1
#include <threads.h>
//---snip---
#elif POSIX_THREADS == 200809L
#include <pthread.h>
//---snip---
#else
int compile_error[-1]; // Induce a compilation error
#endif

void main(void) {}
