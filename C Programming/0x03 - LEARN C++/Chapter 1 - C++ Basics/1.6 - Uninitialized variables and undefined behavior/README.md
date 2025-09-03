# Quiz

# Question# 1

What is an uninitialized variable? Why should you avoid using them?

```
int x; // uninitialized
```

The above is an example of an uninitialized variable. It's best to avoid them as they may lead to unexepected consiquences. For example you can assume it will initialize to 0 then do something like `x += 1;` expecting x to be 1 but instead since we did not initialize it, it gets something random (say 50) and we get 51.

# Question #2

What is undefined behavior, and what can happen if you do something that exhibits undefined behavior?

- Vulnerabilities
- Bugs
- Crashes
- Incorrect results
- etc