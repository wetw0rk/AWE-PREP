#include <iostream>

int main()
{
    int x = { 5 };    // x is a normal integer variable
    int& ref = { x }; // ref is an lvalue reference variable that can now be used as an alias for the variable x

    std::cout << x << '\n';
    std::cout << ref << '\n';

    return 0;
}
