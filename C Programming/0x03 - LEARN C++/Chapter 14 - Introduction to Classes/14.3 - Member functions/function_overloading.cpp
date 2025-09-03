/* Note to self never do this... */

#include <iostream>
#include <string_view>

struct Date
{
    int year = {};
    int month = {};
    int day = {};

    void print()
    {
        std::cout << year << '/' << month << '/' << day;
    }

    void print(std::string_view prefix)
    {
        std::cout << prefix << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 };

    today.print();

    std::cout << '\n';

    today.print("The date is: ");
    std::cout << '\n';

    return 0;
}
