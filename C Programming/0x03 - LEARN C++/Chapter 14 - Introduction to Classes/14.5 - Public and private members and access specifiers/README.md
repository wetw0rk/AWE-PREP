# General Notes

When members are public this means any function can modify them this includes "sub-functions" however when private this is not the case.

- By default **struct** members are **public**
- By default **class** members are **private**
- When naming variables it's best to use best practice such as:
    - **m_**: This allows us to know the variable can be accessed by other functions within the class / struct
    - **g_**: This is generally used by global variables
    - **s_**: This is generally used by static variables

The ONLY difference between a struct and class is how they are defined upon initialization... lol.

# Access levels

Here's a quick table on the different access levels.

| Access level | Access specifier | Derived class access | Public access |
| --- | --- | --- | --- |
| Public | public: | yes | yes | yes |
| Protected | protected: | yes | yes | no |
| Private | private: | yes | no | no |

We can use any number of these there is not limit or order needed when placing these.

# Access level best practices for structs and classes

- **structs** should **AVOID specifiers** altogether, meaning we make the assumption they're public
    - By default structs are set to public
- **classes** should generally only have private, but some functions can be used by the public
    - Generally member variables are private (or protected) and member functions are public

# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:heavy_check_mark:] |
| 2 | [:heavy_check_mark:] |

# Question #1

1. What is a public member?

```cpp
// This struct is public by default 
struct Sample
{
};

class Test
{
public:
    // Anything placed here
};
```

2. What is a private member?

```cpp
// Everything by default is private here
class Test
{
};

class Sample
{
// Everything below is private
private:
    int x;
// Everything starting here is public
public:
    void print()
    {
    }
};
```

3. How many access specifiers are there, and what are they?

```cpp
3 - public, private, protected
```

# Question #2

1. Write a class named `Point3d`. The class should contain:

    - Three private member variables of type `int` named `m_x`, `m_y`, and `m_z`
    - A public member function named `setValues()` that allows you to set values for `m_x`, `m_y`, and `m_z`
    - A public member function named `print()` that prints the Point in the following format: <m_x, m_y, m_z>

Make sure the following program execute correctly:

```cpp
int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    return 0;
}
```

Done, see `q2_pt1.cpp`

2. Add a function named isEqual() to your Point3d class. The following code should run correctly:

```cpp
int main()
{
	Point3d point1{};
	point1.setValues(1, 2, 3);

	Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

	return 0;
}
```

Done, see `q2_pt2.cpp`
