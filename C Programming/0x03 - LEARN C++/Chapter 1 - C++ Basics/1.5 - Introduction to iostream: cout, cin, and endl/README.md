# Introduction to iostream: cout, cin, and endl

# Table of Contents

- [`std::endl` vs `\n`](#stdendl-vs-n)
- [std::cin](#stdcin)
- [Quiz](#quiz)

# `std::endl` vs `\n`

Using `std::endl` is often inefficient compared to `\n` since it does two things.

1. Outputs a newline
2. Flushes the buffer

For this reason, it's often better to use `\n` so we avoid flushing the buffer since C++ is pretty efficient at handling that for us.

# std::cin

`std::cin` reads input from the keyboard using the **extraction operator (>>)**. The input must be stored in a variable to be used.

```c
#include <iostream>

int main()
{
  int x = { 0x00 };

  std::cout << "Enter a number: ";
  std::cin >> x;

  std::cout << "You entered " << x << '\n';

  return 0;
}
```

# Quiz

Consider the following program that we used above:

```c
#include <iostream>  // for std::cout and std::cin

int main()
{
    std::cout << "Enter a number: "; // ask user for a number
    int x{}; // define variable x to hold user input
    std::cin >> x; // get number from keyboard and store it in variable x
    std::cout << "You entered " << x << '\n';
    return 0;
}
```

The program expects you to enter an integer value, as the variable x that the user input will be put into is an integer variable. Run this program multiple times and describe what happens when you enter the following types of input instead:

- A letter such as h
    - 0 is returned since x holds an `int` not a `char`
- A number with a fractional part (e.g 3.2). Try numbers with fractional parts less than 0.5 (e.g 3.2 and 3.7)
    - It seems to always round down so for example 1.9 will return 1 as will 1.2
- A small negative integer, such as -3 
    - The negative number is returned since the number is a `signed int`
- A word, such as Hello
    - 0 is returned
- A really big number (at least 3 billion)
    - 2147483647 is returned since that is the max number an integer can hold
- A small number followed by some letters, such as 123abc
    - Only 123 was output
