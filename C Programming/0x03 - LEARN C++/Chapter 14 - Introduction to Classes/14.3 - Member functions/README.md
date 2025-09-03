# Class types with no data members

It is possible to create class types with no data members. It is also possible to instantiate objects of such a class type as shown below

```cpp
#include <iostream>

struct Foo
{
    void printHi() { std::cout << "Hi!\n"; }
};

int main()
{
    Foo f{};
    f.printHi(); // requires object to call

    return 0;
}
```

However if a class does not have any data members then using a class type is probably overkill. In these cases it's better to use a namespace. This makes it clear that no data is being managed.

```cpp
#include <iostream>

namespace Foo
{
    void printHi() { std::cout << "Hi!\n"; }
};

int main()
{
    Foo::printHi(); // no object needed

    return 0;
}
```

# Quiz

## Question #1

Create a struct called IntPair that holds two integers. Add a member function named print that prints the value of the two integers.

The following program function should compile:

#include <iostream>

// Provide the definition for IntPair and the print() member function here

```cpp
int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	return 0;
}
```

and produce the output:

```
p1: Pair(1, 2)
p2: Pair(3, 4)
```

Below is my struct:

```cpp
struct IntPair
{
    int x = {};
    int y = {};

    void print()
    {
        std::cout << "Pair(" << x << ", " << y << ")\n";
    }
};
```

## Question #2

Add a new member function to IntPair named isEqual that returns a Boolean indicating whether one IntPair is equal to another.

The following program function should compile:

```cpp
#include <iostream>

// Provide the definition for IntPair and the member functions here

int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

	std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}
```

and produce the output:

```cpp
p1: Pair(1, 2)
p2: Pair(3, 4)
p1 and p1 are equal
p1 and p2 are not equal 
```

Below is my struct

```cpp
struct IntPair
{
    int x = {};
    int y = {};

    void print()
    {
        std::cout << "Pair(" << x << ", " << y << ")\n";
    }
    
    int isEqual(const IntPair& pair)
    {
        if (x == pair.x && y == pair.y) {
            return 1;
        }
        return 0;
    }
};
```
