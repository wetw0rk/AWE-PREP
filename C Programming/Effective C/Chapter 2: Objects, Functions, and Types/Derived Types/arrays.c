/*

An array is an allocated sequence of objects that all have the same element type. Array
types are characterized by their element types and the number of elements in the array.


Notes:
  str[i] is the same as *(str + i)
  &str[10] is the same as (str + 10)
  arr[i] at example_two - line 35, is equivalent to *(arr+i)

*/

#include <stdio.h>

int example_one(void)
{
  int ia[11]; /* declare an array of 11 elements of type int identified by ia */
  float *afp[17]; /* declare an array of 17 elements of type float pointer identified by afp */

  /* assigning elements to array */
  char str[11];
  for (unsigned int i = 0; i < 10; ++i)
    str[i] = '0' + i; /* here str is automatically converted to a pointer to X member of the array */
  str[10] = '\0'; /* null terminate final element of array str[10] */
  printf("str: %s\n", str);

}

void func(int arr[5]);
int example_two(void) {
  unsigned int i = 0;
  unsigned int j = 0;
  int arr[3][5]; /* arr is an array of 3 elements, each of which is an array of 5 elements of type int */
  func(arr[i]); /* arr is converted to a pointer to array of 5 elements starting at arr[i] */
  int x = arr[i][j]; /* integer at element i, index j is stored in x */
  return 0;
}
