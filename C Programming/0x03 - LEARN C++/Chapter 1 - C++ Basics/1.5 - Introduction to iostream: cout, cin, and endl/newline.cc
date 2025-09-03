#include <iostream>

int main()
{
  int x = { 5 };

  std::cout << "x is equal to: " << x << '\n'; // Here we avoid flushing AND we treat '\n' as a char (Conventional way)
  std::cout << "Yep." << "\n";                 // Here we treat '\n' as a string AND avoid flushing (Unconventional but works)
  std::cout << "And that's all, folks!\n";     // We use '\n' within the string AND avoid flushing (Conventional)

  return 0;
}
