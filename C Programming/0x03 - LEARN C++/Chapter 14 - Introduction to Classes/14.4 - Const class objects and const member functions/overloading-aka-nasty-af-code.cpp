/* Absolutely nsaty af code please don't do this, i mispelled nasty thats how appualed I am */

#include <iostream>

struct Something
{
    void print()
    {
        std::cout << "non-const\n";
    }

    void print() const
    {
        std::cout << "const\n";
    }
};

int main()
{
    Something s1 = {};

    s1.print();

    const Something s2 = {};

    s2.print();

    return 0;
}
