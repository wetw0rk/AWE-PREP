#include <iostream>

int main()
{
    /* Here we are using cout from the std namespace, where the symbol '::' is an operator called the scope
       resolution operator. If no identifier to the left of the '::' symbol is provided, the global namespace
       is assumed. */
    std::cout << "Hello World\n";
    return 0;
}
