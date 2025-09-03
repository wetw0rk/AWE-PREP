# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:heavy_check_mark:] |
| 2 | [:heavy_check_mark:] |

## Question #1

In a function definition, what are the curly braces and statements in-between called?

```
function body
```

## Question #2

What does the following program print? Do not compile this program, just trace the code yourself.

```c
#include <iostream> // for std::cout

void doB()
{
    std::cout << "In doB()\n";
}

void doA()
{
    std::cout << "In doA()\n";

    doB();
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";

    doA();
    doB();

    std::cout << "Ending main()\n";

    return 0;
}
```

Based on the code above:

```
Starting main()
In doA()
In doB()
In doB()
Ending main()
```
