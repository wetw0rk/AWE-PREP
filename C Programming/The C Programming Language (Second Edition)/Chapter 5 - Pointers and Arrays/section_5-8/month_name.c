#include <stdio.h>

/* month_name: return name of n-th month */
char *month_name(int n)
{
    static char *name[]= \
    {
        "Illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];
}

int main()
{
    char *call;

    call = month_name(12);

    printf("month[%d]= %s\n", 12, call);
}
