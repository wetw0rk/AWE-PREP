# Lvalue references

In C++, a **reference** is an alias for an existing object. Once a reference has been defined, any operation on the reference is applied to the object being referenced.

Modern C++ contains two types of references: `lvalue references` and `rvalue references`.

# Lvalue reference types

An **lvalue reference** acts as an alias for an existing lvalue . To declare an lvalue reference type, we use an ampersand (&) in the type declaration:

```c
int      // a normal int type
int&     // an lvalue reference to an int object
double&  // an lvalue reference to a double object
```

Using this, we can create an **lvaue reference variable** which will act as a reference to an lvalue (normally another variable).

```
NOTE: Although we can use the ampersand with the variable (int &var) it's best practice to place the ampersand next to the type NOT the variable name.

NOTE: Unlike pointers this does not mean "address of" it means "lvalue reference to".
```

Keep in mind any modifications to a reference directly impact the original variable.

# Additional Notes

- Like constants references MUST be initialized.
- Once initialized, a reference in C++ cannot be reseated, meaning it can't be used to reference another object.
- A reference can be destroyed before the object it is referencing.
- The object being referenced can be destroyed before the reference.
- References ARE NOT objects.

# Quiz

## Question #1

Determin what values the following program prints by yourself (do not compile the program).

```c
#include <iostream>

int main()
{
    int x{ 1 };
    int& ref{ x };

    std::cout << x << ref << '\n';

    int y{ 2 };
    ref = y;
    y = 3;

    std::cout << x << ref << '\n';

    x = 4;

    std::cout << x << ref << '\n';

    return 0;
}
```

It will print:

```c
11
22
43
```

Nice I got this one right!
