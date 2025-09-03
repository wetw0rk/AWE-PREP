/* This is important to see, should we have wanted m_name not to be modifiable we would
   have had to place setName under private. Since public members CAN access any private. */

#include <iostream>
#include <string>
#include <string_view>

class Person
{
private:
    std::string m_name = {};

public:
    void kisses(const Person& p) const
    {
        std::cout << m_name << " kisses " << p.m_name << '\n';
    }

    void setName(std::string_view name)
    {
        m_name = name;
    }
};

int main()
{
    Person bob;
    Person kate;

    bob.setName("Bob");
    kate.setName("Kate");

    bob.kisses(kate);

    return 0;
}
