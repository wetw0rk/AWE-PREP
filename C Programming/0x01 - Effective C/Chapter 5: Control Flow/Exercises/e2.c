/*

Exercise 2:

  Change the find_element function from listing 5-13 to return the position
  of the key in a. Don't forget to return an error indication if the key is
  not found.

*/

#include <stdio.h>

size_t find_element(size_t len, int arr[len], int key) {
  size_t pos = (size_t)-1;
  // traverse arr and search for key
  for (size_t i = 0; i < len; i++) {
    if (arr[i] == key) {
      pos = i;
      break; // terminate loop
    }
  }
  return pos;
}

int main()
{
  int r = 0;
  int target = 88;
  int arr[] = { 0, 6, 4, 7, 88, 9 };

  if ((r = find_element(6, arr, target)) >= 0)
    printf("arr[%d] = %d\n", r, arr[r]);
  else
    printf("error: %d\n", r);
    return -1;

  return 0;
}
