/* Example of creating a hash from a string using C++ */

#include <iostream>
#include <vector>
#include <string>

int main() {
  int i = { 0x00 };
  size_t test_hash = { 0x00 };
  std::vector<std::string> names = { "Bob", "Timmy", "Danny" };

  for (i = 0; i < names.size(); i++)
  {
    std::cout << "NAME: " << names[i]
              << " HASH: " << std::hash<std::string>{}(names[i])
	      << std::endl;
  }

  test_hash = std::hash<std::string>{}("test");

  std::cout << "Hash for string \"test\": " << test_hash << std::endl;
}
