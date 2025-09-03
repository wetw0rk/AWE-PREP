# Returning data members effectively

Consider this:

```cpp
#include <iostream>
#include <string>

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
	std::string getName() const { return m_name; } //  getter returns by value
};

int main()
{
	Employee bob{};
	bob.setName("Bob");
	std::cout << bob.getName();

	return 0;
}
```

In this example `getName()` returns `std::string m_name` by value. Although safe, this means a **COPY** of `m_name` will be made **EVERY TIME** `getName()` is called. Since this function is likely to be called alot this is not a good approach.

To fix this, we simply update the example above so that `getName()` returns by const lvalue reference.

```cpp
#include <iostream>
#include <string>

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
	const std::string getName() const { return m_name; } //  getter returns by value by const reference
};

int main()
{
	Employee bob{};
	bob.setName("Bob");
	std::cout << bob.getName();

	return 0;
}
```

Now when `bob.getName()` is invoked, `bob.m_name` is returned by a reference to the caller **AVOIDING** having to make a **COPY**. The caller then uses this reference to print `bob.m_name` to the console.

# What should the return type be?

A member function returning a reference should return a reference of the same type as the data member being returned to avoid unnecessary conversions. For example in the last example if we would have returned `std::string_view` it would have required a temporary `std::string_view` to be created and returned every time the function was called. This is very inefficient.

For getters, using `auto` to have the compiler deduce the return type from the member being returned is a useful way to ensure that no conversions occur:

```c
#include <iostream>
#include <string>

class Employee
{
	std::string m_name{};

public:
	void setName(std::string_view name) { m_name = name; }
	const auto& getName() const { return m_name; } // uses `auto` to deduce return type from m_name
};

int main()
{
	Employee bob{};
	bob.setName("Bob");
	std::cout << bob.getName();

	return 0;
}
```

Although this works, it obscures the return type, so it's best practice to be explicit about what is returned.