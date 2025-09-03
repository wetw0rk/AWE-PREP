#include <iostream>

int main()
{
  /* On most platforms this will return 4 however on others it may return 2 */
  std::cout << sizeof(int) << '\n';

  return 0;
}
