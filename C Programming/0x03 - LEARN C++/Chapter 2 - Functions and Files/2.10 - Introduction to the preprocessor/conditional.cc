#include <iostream>

// If not defined nothing will print!
//#define PRINT_BOB

int main()
{
/*

We could also use other preproccesors such as:

    #ifdef PRINT_BOB
    #ifndef PRINT_BOB
    #if defined(PRINT_BOB)
    #if !defined(PRINT_BOB)

*/

#ifdef PRINT_BOB
    std::cout << "Bob\n";
#endif

#ifdef PRINT_BOB
    std::cout << "Hmm\n";
#endif

    return 0;
}
