# Quiz

# Question #1

What is the difference between a statement and an expression?

```c
int x = {5};   // statement
int x = {2+3}; // expression
```

# Question #2

Indicate whether each of the following lines are statements that do not contain expressions, statements that contain expressions, or are expression statements.

```c
int x;     // statement - no expression
int x = 5; // statement with expression
x = 5;     // expression statements
```

Extra Credit:

```c
foo();          // statement (got this one wrong the answer is expression statement)
std::cout << x; // statements that contain expressions (wrong correct answer is expression statement)
```

# Question #3

Determine what values the following program outputs. Do not compile this program. Just work through it line by line in your head.

```c
#include <iostream>

int main()
{
	std::cout << 2 + 3 << '\n';

	int x{ 6 };
	int y{ x - 2 };
	std::cout << y << '\n';

	int z{ };
	z = x;
	std::cout << z * x << '\n';

	return 0;
}
```

Hmm, based on what I see:

```
5
4
36
```

Noice..
