/*

Unsigned can hold larger positive numbers and no negative values, whereas Signed can
hold positive and negative numbers.

The int type gets its size from the system archetecture (e.g 32bit on x86 machine).
We can specify width by using type definitions from <stdint.h> or <inttypes.h>
headers, like uint32_t.

*/

int main(void)
{
  /* signed integer types */
  signed char;
  short int;
  int;
  long int;
  long long int;
  long long; // we can emit int keyword, in delclaration for these types

  /* unsigned integer types */
  unsigned char;
  unsigned short int;
  unsigned int;
  unsigned long int;
  unsigned long long int;
  unsigned long long; // we can emit int keyword, in delclaration for these types
}
