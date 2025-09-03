#include <iostream>
#include <string>

struct Person
{
    std::string name{};
    int age{};

    void kisses(const Person& person)
    {
        std::cout << name << " kisses " << person.name << '\n';
    }
};

int main()
{
    Person m{ "M", 25 };
    Person a{ "A", 23 };

    m.kisses(a);

    return 0;
}
