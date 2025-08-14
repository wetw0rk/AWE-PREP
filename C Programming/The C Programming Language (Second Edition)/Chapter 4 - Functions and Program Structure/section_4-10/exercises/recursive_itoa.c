/*

Adapt the idea of printd to write a recursive version of itoa; that
is, convert an integer into a string by calling a recursive routine 

Explanation:
 When entering itoa we check if we are dealing with a negative number
 if so we push '-' onto the stack and convert the negative integer to
 a positive. Once done we check if 48 is divisible by 10 then we loop
 with the new number 4 (assuming it was divisible). Since it no longer
 is divisible we push it to the stack `s[i++]`, then n gets 48 and pushes
 that onto the stack.

So execution is as follows:
 if ((48/10) > 0)     -> if ((4/10) > 0)     -> end loop so
    itoa((48/10), s); ->    itoa((4/10), s); -> drop down

 s[i++] = 4  % 10 + '0'; // s[]= {'4'}       <- n now gets assigned 48 automatically
 s[i] = '\0';            // s[]= {'4', '\0'}
 s[i++] = 48 % 10 + '0'; // s[]= {'4', '8'}  <- we overwrite last NULL
 s[i] = '\0';            // s[]= {'4', '8', '\0'}

*/

#include <stdio.h>

/* itoa: convert n to characters in a */
void itoa(int n, char s[])
{
    static int i, j;        /* static var get initialized as 0 when compiled */

    if (j++ == 0 && n < 0)  /* this check will only be performed once  */
    {                       /* if negative convert n to a positive int */
        s[i++] = '-';       /* but add the '-' char at the same time!  */
        n = -n; 
    }

    if ((n/10) > 0)         /* if divisible by 10 and over 0 */
        itoa((n/10), s);    /* call itoa with the new number */

    s[i++] = n % 10 + '0';  /* write the number in reverse!  */
    s[i] = '\0';
}

int main()
{
    char s[10];

    itoa(-48, s);
    printf("%s\n", s);

    return(0);
}
