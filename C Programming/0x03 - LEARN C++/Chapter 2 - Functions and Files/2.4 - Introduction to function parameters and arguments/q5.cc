#include <iostream>

int doubleNumber(int num)
{
    return (num * 2);
}

int getUserInput()
{
    int num;

    std::cout << "Please enter a number: ";
    std::cin >> num;

    return num;
}

int main()
{
    int result = doubleNumber(getUserInput());
    std::cout << "Double your input is: " << result << '\n';
}
