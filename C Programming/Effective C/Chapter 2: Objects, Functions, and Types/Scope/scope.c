#include <stdio.h>

int j;  // file scope of j begins

void f(int i) {                   // block scope of i begins
  int j = i;                      // block scope of j begins; hides file-scope j
  i++;                            // i refers to the function parameter
  for (int i = 0; i < 2; i++) {   // block scope of loop-local i begins
    int j = 2;                    // block scope of inner j begin; hides outer j
    printf("%d\n", j);            // inner j is in scope, prints 2
  }                               // block scope of the inner i and j ends
  printf("%d\n", j);              // the outer j is in scope, prints i
} // the block scope of i and j ends

void g(int j); // j has function prototype scope; hides file-scope j

int main()
{
  f(1);
}
