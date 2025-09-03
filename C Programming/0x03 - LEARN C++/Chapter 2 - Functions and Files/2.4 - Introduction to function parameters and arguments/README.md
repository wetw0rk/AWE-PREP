# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:heavy_check_mark:] |
| 2 | [:heavy_check_mark:] |

## Question #1

What’s wrong with this program fragment?

```c
#include <iostream>

void multiply(int x, int y)
{
    return x * y;
}

int main()
{
    std::cout << multiply(4, 5) << '\n';

    return 0;
}
```

multiply must return an int, NOT a void.

## Question #2

What two things are wrong with this program fragment?

```c
#include <iostream>

int multiply(int x, int y)
{
    int product{ x * y };
}

int main()
{
    std::cout << multiply(4) << '\n';

    return 0;
}
```

Firstly multiply returns nothing, secondly it requires 2 parameters from the caller and main() only supplys one.

## Question #3

What value does the following program print?

```c
#include <iostream>

int add(int x, int y, int z)
{
    return x + y + z;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    std::cout << multiply(add(1, 2, 3), 4) << '\n';

    return 0;
}
```

Based on the above.

```
24
```

## Question #4

Write a function called doubleNumber() that takes one integer parameter. The function should return double the value of the parameter.

```c
int doubleNumber(int num)
{
    return (num * 2);
}
```

## Question #5

Write a complete program that reads an integer from the user, doubles it using the doubleNumber() function you wrote in the previous quiz question, and then prints the doubled value out to the console.

```c
#include <iostream>

int doubleNumber(int num)
{
    return (num * 2);
}

int getUserInput()
{
    int num;

    std::cout << "Please enter a number: ";
    std::cin >> num;

    return num;
}

int main()
{
    int result = doubleNumber(getUserInput());
    std::cout << "Double your input is: " << result << '\n';
}
```
