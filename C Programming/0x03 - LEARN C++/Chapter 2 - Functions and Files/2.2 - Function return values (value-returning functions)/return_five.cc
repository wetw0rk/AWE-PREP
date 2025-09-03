#include <iostream>

// int is the return type
// A return of type int means the function will return some integer value to the caller
int returnFive()
{
    // The return statement indicates the specific value that will be returned
    return 5;
}

int main()
{
    std::cout << returnFive() << '\n';
    std::cout << returnFive() + 2 << '\n';

    returnFive(); // The value 5 is returned, but is ignored since main() doesn't do anything with it

    return 0;
}
