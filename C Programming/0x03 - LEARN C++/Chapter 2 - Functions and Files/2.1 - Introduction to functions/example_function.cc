#include <iostream>

// Definition of user-defined function doPrint()
void doPrint()
{
    std::cout << "\tIn doPrint()\n";
}

int main()
{
    std::cout << "Starting main()\n";

    doPrint(); // Call the function doPrint() from main(). Here main() is the caller
    doPrint();

    std::cout << "Ending main()\n";

    return 0;
}
