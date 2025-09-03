#include <iostream>

struct Ball
{
    std::string m_color = {};
    double m_color_num = { 0x00 };
};

void print(Ball b)
{
    std::cout << "Ball(" << b.m_color << ", " << b.m_color_num << ")\n";
}

int main()
{
	Ball blue{ "blue", 10.0 };
	print(blue);

	Ball red{ "red", 12.0 };
	print(red);

	return 0;
}
