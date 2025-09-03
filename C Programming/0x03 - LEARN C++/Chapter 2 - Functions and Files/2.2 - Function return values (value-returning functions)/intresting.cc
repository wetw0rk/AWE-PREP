#include <iostream>

int willCompile()
{
    return 6;
    return 7;
}

int main()
{
    std::cout << willCompile() << '\n';

    return 0;
}
