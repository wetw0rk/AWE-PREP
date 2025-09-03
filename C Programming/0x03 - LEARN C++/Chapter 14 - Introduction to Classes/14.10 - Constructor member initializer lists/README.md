# Member initialization via a member initialization list

To have a constructor initialize members, we do so using  a**member initializer list**. 

Below is an example.

```c
  1 #include <iostream>
  2 
  3 class Foo
  4 {
  5 private:
  6     int m_x {};
  7     int m_y {};
  8  
  9 public:
 10     Foo(int x, int y) : m_x { x }, m_y { y }
 11     {
 12         std::cout << "Foo(" << x << ", " << y << ") constructed\n";
 13     }
 14     
 15     void print() const
 16     {
 17         std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
 18     }
 19 };
 20 
 21 int main()
 22 {
 23     Foo obj = { 7, 7 };
 24     obj.print();
 25  
 26     return 0;
 27 }
```

However best practice is to use this format:

```c
 10     Foo(int x, int y)
 11         : m_x { x }
 12         , m_y { y }
 13     {   
 14         std::cout << "Foo(" << x << ", " << y << ") constructed\n";
 15     }
```

# Order Matters!

The members in a member initializer list are always initialized in the order in which they are defined inside the class - NOT THE ORDER IN THE INTIALIZER LIST! In the following:

```c
Foo(int x, int y) : : m_y{ std::max(x, y) }, m_x{ m_y }
```

x will get initialized BEFORE y. This means that becuase m_x gets initialized with the value of m_y which has not been initialized yet. This can cause huge errors.

```
BEST PRACTICE: Member variables in a member initializer list should be listed in order that they are defined in the class :)
```

# Quiz

## Question #1

Write a class named Ball. Ball should have two private member variables, one to hold a color, and one to hold a radius. Also write a function to print out the color and radius of the ball.

The following sample program should compile:

```c
int main()
{
	Ball blue{ "blue", 10.0 };
	print(blue);

	Ball red{ "red", 12.0 };
	print(red);

	return 0;
}
```

and produce the result:

```c
Ball(blue, 10)
Ball(red, 12
```

Below is mi code:

```c
  3 struct Ball
  4 {
  5     std::string m_color = {};
  6     double m_color_num = { 0x00 };
  7 };  
  8 
  9 void print(Ball b)
 10 {
 11     std::cout << "Ball(" << b.m_color << ", " << b.m_color_num << ")\n";
 12 }   
 13 
 14 int main()
 15 {
 16     Ball blue{ "blue", 10.0 };
 17     print(blue);
 18     
 19     Ball red{ "red", 12.0 };
 20     print(red);
 21     
 22     return 0;
 23 }   
```

Below was the answer:

```c
#include <iostream>
#include <string>
#include <string_view>

class Ball
{
private:
	std::string m_color{ "none" };
	double m_radius{ 0.0 };

public:
	Ball(std::string_view color, double radius)
		: m_color{ color }
		, m_radius{ radius }
	{
	}

	const std::string& getColor() const { return m_color; }
	double getRadius() const { return m_radius; }
};

void print(const Ball& ball)
{
    std::cout << "Ball(" << ball.getColor() << ", " << ball.getRadius() << ")\n";
}

int main()
{
	Ball blue{ "blue", 10.0 };
	print(blue);

	Ball red{ "red", 12.0 };
	print(red);

	return 0;
}
```

was a little confused BUT I see now what was wanted.

## Question #2

Why did we make `print()` a non-member function instead of a member function?

```
Getter functions hide uneeded operations?
```

Answer - encapsulation (same stuff)

## Question #3

Why did we make m_color a std::string instead of a std::string_view?

```
Since we wanted the string to be stored in the object. std::string_view requires the object to be "alive" from the caller.
```