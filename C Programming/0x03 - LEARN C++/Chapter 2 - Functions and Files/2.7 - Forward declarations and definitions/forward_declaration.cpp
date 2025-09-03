#include <iostream>

int add(int x, int y); // Forward declaration of add() (using a function declaration / function prototype)

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3,4) << '\n'; // This works because we forward declared add() above
    return 0;
}

// Here we define the body of add()
int add(int x, int y)
{
    return x + y;
}
