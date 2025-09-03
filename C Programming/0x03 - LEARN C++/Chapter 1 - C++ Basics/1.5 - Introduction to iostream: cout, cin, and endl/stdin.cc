#include <iostream>

int main()
{
  int x = { 0x00 };

  std::cout << "Enter a number: ";
  std::cin >> x;

  std::cout << "You entered " << x << '\n';

  return 0;
}
