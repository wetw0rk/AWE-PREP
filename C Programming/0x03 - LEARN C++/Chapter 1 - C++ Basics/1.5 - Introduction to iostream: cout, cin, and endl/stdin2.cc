#include <iostream>

int main()
{
  int x = { 0x00 };
  int y = { 0x00 };

  // Here we see we can store multiple values using one line
  std::cout << "Enter two numbers seperated by a space: ";
  std::cin >> x >> y;

  std::cout << "You entered " << x << " and " << y << '\n';

  return 0;
}
