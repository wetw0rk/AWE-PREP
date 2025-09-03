#include <iostream>

void doB()
{
    std::cout << "\t\tIn doB()\n";
}

void doA()
{
    std::cout << "\tStarting doA()\n";

    doB();

    std::cout << "\tEnding doA()\n";
}

int main()
{
    std::cout << "Starting main()\n";

    doA();

    std::cout << "Ending main()\n";

    return 0;
}
