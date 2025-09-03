#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)
#define paste(front, back) front ## back

int main()
{
    dprint(5/9);
    
    char paste(name, 1)[]="bob";
    printf("%s\n", name1);
}
