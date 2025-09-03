#include <iostream>

// This function takes no parameters and does not rely on the caller
// for anything.
void doPrint()
{
    std::cout << "In doPrint()\n";
}

// This function takes one integer parameter named x. The caller
// will supply the value of x.
void printValue(int x)
{
    std::cout << x << '\n';
}

// This function has two integer parameters, one named x, and one named y. Here
// the caller will supply both x and y
int add(int x, int y)
{
    return x + y;
}

int main()
{
    doPrint();
    printValue(add(2, 3));
}
