#include <iostream>

int main()
{

// Will compile if 1, will not if 0
#if 0
    std::cout << "Hello ";
#endif

    std::cout << "Bob\n";

    return 0;
}
