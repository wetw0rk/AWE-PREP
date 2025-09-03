# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:heavy_check_mark:] |

## Question #1

Inspect the following programs and state what they output, or whether they will not compile.

1.

```c
#include <iostream>

void printA()
{
    std::cout << "A\n";
}

void printB()
{
    std::cout << "B\n";
}

int main()
{
    printA();
    printB();

    return 0;
}
```

This will output:

```
A
B
```

2. 

```c
#include <iostream>

void printA()
{
    std::cout << "A\n";
}

int main()
{
    std::cout << printA() << '\n';

    return 0;
}
```

This will not compile.
