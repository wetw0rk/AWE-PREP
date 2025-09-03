#include <iostream>


/* Here we use the class keyword over the struct and declare a class */
class Date
{
    // Class members are private and can only be accessed by other members
    int m_year = {};
    int m_month = {}; /* In C++ it's common to use the "m_" prefix to easily differentiate date members. This
                         is the same reason we use "g_" for globals and "s_" for static variables. Ultimately
                         this is considered best practice. */
    int m_day = {};

    void print() const
    {
        std::cout << m_year << '/' << m_month << '/' << m_day;
    }
};

int main()
{
    Date today { 2020, 10, 14 }; /* This will throw an error can no longer aggregate initialization */

    /* This will also throw an error since every member is private */
    today.m_day = 16;
    today.print();

    return 0;
}
