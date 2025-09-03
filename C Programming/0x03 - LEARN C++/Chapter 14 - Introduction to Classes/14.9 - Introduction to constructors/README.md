# Introduction to constructors

When a class type is an aggregate, we can use aggregate initialization to initialize that class directly.

```c
struct Foo // Foo is an aggregate
{
    int x {};
    int y {};
};

int main()
{
    Foo foo { 6, 7 }; // uses aggregate initialization

    return 0;
}
```

However, as soon as we make any member variables private (to hide our data) our class type is no longer an aggregate. This means we can no longer do what we did above. Regardless there's some downsides to what we see above.

- We must know the implementation of the class to know the order in which to initialize members
- If we had some kind of invariant, we are relying on the user to know it

TLDR though - Regardless in order to initialize private members  we need a matching constructor.

# Constructors

A **constructor** is a special member function that is automatically called after a non-aggregate class type object is created.

Constructors generally perform two functions:

- They typically perform initialization of any member variables
- They perform other setup functions - this may include error checking initialization values

After the constructor finishes executing, we say that the object has been "constructed", and the object should now be in a consistent, usable state.

However, constructors have rules to how they must be named

- Constructors must have the same name as the class (same capitalization).
- Constructors have no return type (not even `void`)

Below is a basic constructor.

```c
  1 #include <iostream>
  2 
  3 class Foo
  4 {
  5 private:
  6     int m_x = {};
  7     int m_y = {};
  8 
  9 public:
 10     // This is the constructor function
 11     Foo(int x, int y)
 12     {
 13         std::cout << "Foo(" << x << ", " << y << ") constructed\n";
 14     }
 15 
 16     void print() const
 17     {
 18         std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
 19     }
 20 };
 21 
 22 int main()
 23 {
 24     Foo obj{ 7, 7 };
 25 
 26     obj.print();
 27 
 28     return 0;
 29 }
```

Once compiled we see the following.

```c
$ ./demo 
Foo(7, 7) constructed
Foo(0, 0)
```

When the compiler sees the definition `Foo obj {7, 7}`, it looks for a matching `Foo` constructor that will accept two `int` arguments. `Foo(int, int)` is a match, so the compiler will allow the definition.

Here when we called the `print()` member function, we got 0 since the constructor function did not actually initialize the members.