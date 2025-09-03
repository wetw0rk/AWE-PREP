# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:heavy_check_mark:] |
| 2 | [:heavy_check_mark:] |
| 3 | [:heavy_check_mark:] |
| 4 | [:heavy_check_mark:] |
| 5 | [:heavy_check_mark:] |

## Question #1

What is a function prototype

```cpp
// When we use a forward declaration for example, in the following code add() would be a function prototype
#include <iostream>

int add(int x, int y); // Forward declaration of add() (using a function declaration / function prototype)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3,4) << '\n'; // This works because we forward declared add() above
    return 0;
}
```

## Question #2

What is a forward declaration?

```
Same as above...
```

## Question #3

How do we declare a forward declaration for functions?

```
See Q1
```

## Question #4

Write the function declaration for this function (use the preferred form with names):

```cpp
int doMath(int first, int second, int third, int fourth)
{
     return first + second * third / fourth;
}
```

Pretty easy:

```cpp
int doMath(int first, int second, int third, int fourth);
```

## Question #5

For each of the following programs, state whether they fail to compile, fail to link, or compile and link successfully. If you are not sure, try compiling them!

1.

```cpp
#include <iostream>
int add(int x, int y);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y)
{
    return x + y;
}
```

Based on the above without compiling it will fail to compile since add() only takes 2 arguments NOT 3.

2.

```cpp
#include <iostream>
int add(int x, int y);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```

I think it will compile since the prototype is taking 2 args vs 3...

3.

```cpp
#include <iostream>
int add(int x, int y);

int main()
{
    std::cout << "3 + 4 = " << add(3, 4) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```

Hmm this one is tough... I think it will fail to link.

4.

```cpp
#include <iostream>
int add(int x, int y, int z);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int z, int y, int x) // names don't match the declaration
{
    return x + y + z;
}
```

Will compile since the types are correct (names don't matter)

5.

```cpp
#include <iostream>
int add(int, int, int);

int main()
{
    std::cout << "3 + 4 + 5 = " << add(3, 4, 5) << '\n';
    return 0;
}

int add(int x, int y, int z)
{
    return x + y + z;
}
```

Will compile :)
