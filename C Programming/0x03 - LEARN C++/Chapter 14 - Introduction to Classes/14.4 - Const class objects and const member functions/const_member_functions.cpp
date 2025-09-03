/* BEST PRACTICE: A member function that does not (and will not ever) modify the state of the object should be made const, so that it can be called on both const and non-const objects. */

#include <iostream>

struct Date
{
    int year = {};
    int month = {};
    int day = {};

    /* IMO whoever thought of this syntax needs to be on an FBI watch list... "const void" would
       have looked alot better and makes more sense to C programmers... Anyway, this needs to be
       done in order for "today" in in main() to call the print() member function. Should we opt
       out of this, we will get a compiler error. However, non-const types can call print(), you
       can see this in the example below with "tommorow". */
    void print() const
    {
        std::cout << year << '/' << month << '/' << day << '\n';
    }
};

int main()
{
    const Date today { 2020, 10, 14}; // We declare today to be a const of type Date
    Date tommorow { 2020, 11, 14 };

    today.print();
    tommorow.print();

    return 0;
}
