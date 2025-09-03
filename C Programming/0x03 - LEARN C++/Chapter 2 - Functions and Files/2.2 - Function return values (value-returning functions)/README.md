# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:heavy_check_mark:] |
| 2 | [:heavy_check_mark:] |

## Question #1

Inspect (do not compile) each of the following programs. Determine what the program will output, or whether the program will generate a compiler error.

Assume you have “treat warnings as errors” turned off.

1.

```c
#include <iostream>

int return7()
{
    return 7;
}

int return9()
{
    return 9;
}

int main()
{
    std::cout << return7() + return9() << '\n';

    return 0;
}
```

Hmm, based on the above no errors - number 16.

2. 

```c
#include <iostream>

int return7()
{
    return 7;

    int return9()
    {
        return 9;
    }
}

int main()
{
    std::cout << return7() + return9() << '\n';

    return 0;
}
```

This will not compile... C++ does not support nested functions.

3. 

```c
#include <iostream>

int return7()
{
    return 7;
}

int return9()
{
    return 9;
}

int main()
{
    return7();
    return9();

    return 0;
}
```

This will not return anything, however will compile. The data needs to be told what to do (e.g write to STDOUT).

4. 

```c
#include <iostream>

int getNumbers()
{
    return 5;
    return 7;
}

int main()
{
    std::cout << getNumbers() << '\n';
    std::cout << getNumbers() << '\n';

    return 0;
}
```

This will not compile a function CANNOT use two return statements like this. - Actually I was wrong it will compile, return 7 will just never execute...

5. 

```c
#include <iostream>

int return 5()
{
    return 5;
}

int main()
{
    std::cout << return 5() << '\n';

    return 0;
}
```

Will not comple since the function definition cannot use a space.

6. 

```c
#include <iostream>

int returnFive()
{
    return 5;
}

int main()
{
    std::cout << returnFive << '\n';

    return 0;
}
```

Will return an address since we are not invoking the function rather passing its address?


## Question #2

What does “DRY” stand for, and why is it a useful practice to follow?

```
Don't
Repeat
Yourself
```
