# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:heavy_check_mark:] |

## Question #1

What does the following program print?

```c
#include <iostream>

void doIt(int x)
{
    int y{ 4 };
    std::cout << "doIt: x = " << x << " y = " << y << '\n';

    x = 3;
    std::cout << "doIt: x = " << x << " y = " << y << '\n';
}

int main()
{
    int x{ 1 };
    int y{ 2 };

    std::cout << "main: x = " << x << " y = " << y << '\n';

    doIt(x);

    std::cout << "main: x = " << x << " y = " << y << '\n';

    return 0;
}
```

Based on the above:

```
x = 1 y = 2
doIt: x = 1 y = 4
doIt: x = 3 y = 4
x = 1 y = 2
```
