/*

Rewrite the routines day_of_year and month_day with
pointers instead of indexing.

*/

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int leap, i = 1;
    char *ptr;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    ptr = &daytab[leap][1];

    while (i < month)
        day += *ptr++, i++;
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap, i = 1;
    char *ptr;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    ptr = &daytab[leap][1];

    while (yearday > *ptr)
        yearday -= *ptr++, i++;

    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int month, day;
    int test;

    month_day(1988, 60, &month, &day);
    printf("month_day(1988, 60, &month, &day) = %d/%d/1988\n", month, day);

    test = day_of_year(1988, 2, day);
    printf("day_of_year(1988, 2, day) = %d\n", test);

    return 0;
}
