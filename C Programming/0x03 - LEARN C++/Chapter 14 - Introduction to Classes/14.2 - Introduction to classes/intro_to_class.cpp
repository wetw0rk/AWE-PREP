#include <iostream>

class Date
{
public:                // This is called an access specifier
    int m_day = {};    // Added "m_" prefixes to each of the member names
    int m_month = {};
    int m_year = {};
}

/* Here Date& signifies that it takes a reference to a Date object as a parameter. The
   const means that the function promises not to modify the Date object within it. */
void printDate(const Date& date)
{
    std::cout << date.m_day << '/' << date.m_month << '/' << date.m_year;
}

int main()
{
    Date date{ 4, 10, 21 };

    printDate(date);

    return 0;
}
