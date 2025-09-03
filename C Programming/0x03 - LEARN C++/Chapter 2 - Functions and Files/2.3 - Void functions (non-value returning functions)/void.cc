#include <iostream>

// void means the function does not return a value to the caller
void printHi()
{
    std::cout << "Hi\n";
    // This function does not return a value so no return statement is needed
}

int main()
{
    printHi();

    return 0;
}
