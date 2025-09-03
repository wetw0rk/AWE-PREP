/*
write a program to determine the ranges of char, short, int, and long variables, both
signed and unsigned, by printing appropriate values from standard headers, and direct
computation. Harder if you compute them: determine the ranges of the various floating
point types.
*/


#include <stdio.h>  /* library for standard I/O          */
#include <limits.h> /* constants for integral type sizes */

int main()
{
    printf("DataType\t\tMin\t\tMax\n\n");
    printf("char %21d %15d\n", CHAR_BIT, CHAR_BIT);                     /* char                   */
    printf("unsigned char %12d %16d\n", 0, UCHAR_MAX);                  /* unsigned char          */
    printf("signed char %15d %15d\n", SCHAR_MIN, SCHAR_MAX);            /* signed char            */
    printf("signed short int %11d %15d\n", SHRT_MIN, SHRT_MAX);         /* signed short int       */
    printf("unsigned short int %7d %17d\n", 0, USHRT_MAX);              /* unsigned short int     */
    printf("signed int %19d %15d\n", INT_MIN, INT_MAX);                 /* signed int             */
    printf("unsigned int %13d %15d\n", 0, UINT_MAX);                    /* unsigned int           */
    printf("signed long int %10d %15d\n", LONG_MIN, LONG_MAX);          /* signed long int        */
    printf("unsigned long int %8d %15d\n", 0, ULONG_MAX);               /* unsigned long int      */
    printf("signed long long int %5d %15d\n", LLONG_MIN, LLONG_MAX);    /* signed long long int   */
    printf("unsigned long long int %3d %15d\n", 0, ULLONG_MAX);         /* unsigned long long int */
}
