#include <iostream>
#include <string>

class Employee
{
    std::string m_name = {};
    char m_firstInitial = {};

public:

    void setName(std::string_view name)
    {
        m_name = name;
        m_firstInitial = name.front(); // use std::string::front() to get the first letter of `name`
    }

    void print() const
    {
        std::cout << "Employee " << m_name << " has first inital " << m_firstInitial << '\n';
    }
};

int main()
{
    Employee e = {};

    e.setName("Sam");
    e.print();

    e.setName("Ashley");
    e.print();

    return 0;
}
