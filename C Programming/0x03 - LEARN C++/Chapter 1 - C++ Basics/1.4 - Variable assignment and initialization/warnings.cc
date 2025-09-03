// g++ -std=c++17 -Wall -o test warnings.cpp

int main()
{
  int x { 5 };
  [[maybe_unused]] double pi { 3.14159 };

  // x not used so error will be generated

  return 0;
}
