/*

There is no error checking in day_of_year or month_day.
Remedy this defect.

*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day, int current_year)
{
    int i, leap;

    /* make sure there's only 1-12 months */
    if (month > 12 || month < 1) {
        printf("error: there are only 12 months in a year\n");
        exit(-1);
    }
    /* check that the year provided is lower than the current year */
    if (year > current_year || year <= 0) {
        printf("error: the current year is %d, negative year or too big\n", current_year);
        exit(-1);
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday, int current_year)
{
    int i, leap;

    /* check that the year provided is lower than the current year */
    if (year > current_year || year <= 0) {
        printf("error: the current year is %d, negative year or too big\n", current_year);
        exit(-1);
    }
    /* there are only 365 days a year so check it */
    if (yearday > 365 || yearday < 0) {
        printf("error: there are only 365 days a year\n");
        exit(-1);
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int test;
    int month, day;
    time_t ct = time(NULL);
    struct tm tm = *localtime(&ct);
    int current_year = tm.tm_year+1900;

    month_day(2018, 60, &month, &day, current_year);
    printf("month_day(1988, 60, &month, &day) = %d/%d/1988\n", month, day);

    test = day_of_year(2019, 2, day, current_year);
    printf("day_of_year(1988, 2, day) = %d\n", test);

    return 0;
}
