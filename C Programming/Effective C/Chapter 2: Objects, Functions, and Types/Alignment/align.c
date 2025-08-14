/*

An alignment represents the number of bytes between seccessive addresses at which a given
object can be allocated. C11 introduced a simple way for specifying alignments. Every
valid alignment is a nonnegative intergral power of two. An object type imposes a default
alignment requirement on every object of that type: stricter alignment (a larger power of
two) can be requested using the alignment specifier (_Alignas).

*/

struct S {
  int i;
  double d;
  char c;
};

int main(void)
{
  unsigned char bad_buff[sizeof(struct S)];
  _Alignas(struct S) unsigned char good_buff[sizeof(struct S)];

  struct S *bad_s_ptr = (struct S *)bad_buff; // wrong pointer alignment
  struct S *good_s_ptr = (struct S *)good_buff; // corrent pointer alignment
}
