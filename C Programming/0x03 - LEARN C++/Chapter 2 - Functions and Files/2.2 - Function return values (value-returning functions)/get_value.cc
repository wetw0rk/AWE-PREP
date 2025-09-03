#include <iostream>

int getValueFromUser() // This function returns an integer value
{
    int input = {};

    std::cout << "Enter an integer: ";
    std::cin >> input;

    return input;
}

int main()
{
    int num = { getValueFromUser() }; // We can initialize num with the return value of getValueFromUser()

    std::cout << num << " doubled is: " << (num * 2) << '\n';

    return 0;
}
