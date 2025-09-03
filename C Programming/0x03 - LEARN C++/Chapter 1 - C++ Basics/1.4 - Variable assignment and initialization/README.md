# Variable assignment and initialization

This section is about how to actually put values into variables and use those values.

# Table of Contents

- [Different forms of initialization](#different-forms-of-initialization)
- [Unused initialized variables warnings](#unused-initialized-variables-warnings)
  - [The `[[maybe_unused]]` attribute](#the-maybe_unused-attribute)
- [Quiz](#quiz)
  - [Question #1](#question-1)
  - [Question #2](#question-2)
  - [Question #3](#question-3)


# Different forms of initialization

There are 6 basic ways to initialize variables in C++.

| Method | Example(s) | Description |
| --- | --- | --- |
| Default Initialization | `int x;` | Leaves a variable with an indeterminate value (random) |
| Copy Initialization | `int x = 5;` | This form was inherited from C |
| Direct Initialization | `int x(5);` | Initially introduced to me a more efficient initialization method but since it looks alot like a function - it created alot of confusion and may not be as widely deployed as originally intended. |
| List Initialization | `int x { 5 };` <br> `int x = { 5 };` <br> `int x {};` | List initialization has the benefit of "narrowing conversions" so for example if we passed `int x { 4.5 }` the compiler would produce an error. This is generally the preferred method of initialization |
| Value and Zero Initialization | `int x {};` | When a variable is initialized using empty braces, value initialization takes place. In most cases, value initialization will initialize the variable to zero (or empty, if that’s more appropriate for a given type). In such cases where zeroing occurs, this is called zero initialization. |
| Multiple Variable Initializing | `int x = 5, y = 6` | Basically initialization on the same line |

# Unused initialized variables warnings

Most compilers will prodce a warning if we declare a variable and it is not used anywhere. However since I'm using `g++` we must specify the `-Wall` command to show all warnings.

```bash
$ g++ -std=c++17 -Wall -o test warnings.cc
warnings.cc: In function ‘int main()’:
warnings.cc:5:7: warning: unused variable ‘x’ [-Wunused-variable]
    5 |   int x { 5 };
      |       ^
```

## The `[[maybe_unused]]` attribute

Sometimes we may want to leave a variable unused until the function is coded. To do so we'd use the `[[maybe_unused]]` attribute.

```c
// https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
int main()
{
    [[maybe_unused]] double pi { 3.14159 };
    [[maybe_unused]] double gravity { 9.8 };
    [[maybe_unused]] double phi { 1.61803 };

    // the above variables will not generate unused variable warnings

    return 0;
}
```

# Quiz    
                                                           
| Question | Correct |
| --- | --- | 
| 1 | [:heavy_check_mark:] |
| 2 | [:x:] |
| 3 | [:heavy_check_mark:] |

## Question #1

What is the difference between initialization and assignment?

```
Initialization is when we declare something to be a value e.g "int a = { 7 };" would be an initialized
value and "a = 10;" would be us declaring a to now be 10.
```

## Question #2

What form of initialization should you prefer when you want to initialize a variable with a specific value?

```
List Initialization / Copy Initialization
```

Correct Answer: `Direct list initialization (aka. direct brace initialization).`

## Question #3

What are default initialization and value initialization? What is the behavior of each? Which should you prefer?

```c
int x;   // default
int x{}; // value initialization (Preferred)
```
