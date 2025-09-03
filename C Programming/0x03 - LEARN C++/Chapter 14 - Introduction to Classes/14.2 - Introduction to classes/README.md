# Quiz

| Question | Correct |
| --- | --- |
| 1 | [:x:] |

## Question #1

Given some set of values (ages, address numbers, etc…), we might want to know what the minimum and maximum values are in that set. Since the minimum and maximum values are related, we can organize them in a struct, like so:

```cpp
struct minMax
{
    int min; // holds the minimum value seen so far
    int max; // holds the maximum value seen so far
};
```

However, as written, this struct has an unspecified class invariant. What is the invariant?

Not sure what is being asked but I would say:

```cpp
class MinMax
{
public:
    int m_min = {};
    int m_max = {}; 
}
```

AH my bad so the answer was: The invariant is that min <= max. If min is ever greater than max, any code that uses this struct may malfunction.
