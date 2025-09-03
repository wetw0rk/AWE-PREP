#include <iostream>
#include <string>

class Ball
{
private:
  
  std::string default_color = {"black"};
  double default_radius = {10.0};

  std::string m_color = {};
  double m_radius = {};

public:

  Ball(std::string color = default_color, double radius = default_radius)
    : m_color { color }
    , m_radius { radius }
  {
    std::cout << m_color;
  }

};

int main()
{
  Ball def {};
  Ball blue { "blue" };
  Ball twenty{ 20.0 };
  Ball blueTwenty{ "blue", 20.0 };

  return 0;
}
