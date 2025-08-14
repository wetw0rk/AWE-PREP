#include <stdio.h>
#include <stddef.h>
#include <stdalign.h>
#include <assert.h>

int main(void) {
  int arr[4];
  static_assert(_Alignof(arr) == 4, "unexpected alignment"); // static assert
  assert(alignof(max_align_t) == 16); // runtime assertion (assert(): checks to see if the expression is false and if so prints to stderr)
  printf("Alignment of arr = %zu\n", _Alignof(arr));
  printf("Alignment of max_align_t = %zu\n", alignof(max_align_t));
  return 0;
}
