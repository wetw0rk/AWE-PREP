/*

The basic char set lacks non-english letters. To address this need, the C Standards
committee specified a new, wide type to allow large character sets. You can represent
the characters of a large character set as wide characters by using the wchar_t type,
which generally takes more space than a basic character.

*/

#include <stdio.h>
#include <stdlib.h> /* wchar_t */
#include <locale.h> /* setlocale() */

int main(void)
{
  wchar_t *var = L"Привет мир\n"; /* hello world in russian */

  setlocale(LC_ALL, "C.UTF-8"); /* Allow UTF-8 vs POSIX (which is ASCII only) */
  
  if (printf("%ls\n", var) < 0)
    perror("printf");
}
