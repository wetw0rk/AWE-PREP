#include <iostream>

struct Date
{
    int year = {};
    int month = {};
    int day = {};

    void print()
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

int main()
{
    Date today { 2020, 10, 14 };

    today.day = 16;
    today.print();

    return 0;
}
