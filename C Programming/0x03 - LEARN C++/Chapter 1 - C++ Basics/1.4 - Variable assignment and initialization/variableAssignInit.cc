// g++ -std=c++17 -o test variableAssignInit.cpp

#include <iostream>

int main()
{
  int width;              // variable un-initialized
  width = 5;              // assign 5 to variable

  std::cout << width;     // sends 5 to STDOUT

  width = 7;              // assign 7 to variable

  std::cout << width;     // sends 7 to STDOUT

  std::cout << std::endl; // flush output buffer and send newline

  // Different forms of initialization
  int a;         // no initializer (default initialization)
  int b = 5;     // initial value after equals sign (copy initialization)
  int c(6);      // initial value in paraenthesis (direct initialization)

  // List initilialization methods (C++11) (preferred)
  int d { 7 };   // initial value in braces (direct list initialization)
  int e = { 8 }; // initial value in braces after equals sign (copy list initialization)
  int f {};      // initializer is empty braces (value initialization)

  std::cout << "a holds: " << a << std::endl;
  std::cout << "b holds: " << b << std::endl;
  std::cout << "c holds: " << c << std::endl;
  std::cout << "d holds: " << d << std::endl;
  std::cout << "e holds: " << e << std::endl;
  std::cout << "f holds: " << f << std::endl;

  return 0;
}
