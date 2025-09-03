#include <iostream>

/* struct members are public by default */
struct Date
{
    /* public means anyone can access these variables*/
    int year = {};
    int month = {};
    int day = {};

    /* public also means anyone can access this function */
    void print() const
    {
        std::cout << year << '/' << month << '/' << day;
    }
};

/* The main() function is an example of being within the "public" space */
int main()
{
    Date today { 2020, 10, 14 };

    today.day = 16;
    today.print();

    return 0;
}
