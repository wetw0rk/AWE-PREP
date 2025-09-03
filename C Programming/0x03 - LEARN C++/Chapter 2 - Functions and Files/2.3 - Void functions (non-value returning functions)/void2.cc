#include <iostream>

// void means the function does not return a value to the caller
void printHi()
{
    std::cout << "Hi\n";

    return; // Tell the compiler to return to the caller -- This is redundant since the return will happen anyway (this is not needed).
}

int main()
{
    printHi();

    return 0;
}
