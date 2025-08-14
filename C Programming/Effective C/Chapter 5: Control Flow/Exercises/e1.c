/*

Exercise 1:

  Modify the function from Listing 5-11 to make it clear to the caller which
  file could not be opened.

*/

#include <stdio.h>
#include <stdlib.h>

typedef int object_t;

enum Errors {
  FILE1_WE,
  FILE2_WE,
  OBJECT_ALLOC
};

int do_something(void)
{
  FILE *file1, *file2;
  object_t *obj;

  int ret_val = 0; // Initially assume a successful return value

  file1 = fopen("a_file", "w");
  if (file1 == NULL) {
    ret_val = FILE1_WE;
    goto FAIL_FILE1;
  }

  file2 = fopen("another_file", "w");
  if (file2 == NULL) {
    ret_val = FILE2_WE;
  }

  obj = malloc(sizeof(object_t));
  if (obj == NULL) {
    ret_val = OBJECT_ALLOC;
    goto FAIL_OBJ;
  }

  // Operate on allocated resources

  // Clean up everything
  free(obj);

FAIL_OBJ:
  fclose(file2);
FAIL_FILE2:
  fclose(file1);
FAIL_FILE1:
  return ret_val;
}

int main()
{
  int r = do_something();
  switch (r) {
    case FILE1_WE:
      printf("Failed to open file1 in write mode\n");
      break;
    case FILE2_WE:
      printf("Failed to open file2 in write mode\n");
      break;
    case OBJECT_ALLOC:
      printf("Failed to allocate object\n");
      break;
    default:
      printf("Error in function do_something()\n");
      break;
  }
  return r;
}
