/*

Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point
number may be followed by e or E and an optionally signed exponent.

Equation : 123.45 * 10^-6 = answer (format with %.8f)
  C: double answer = (123.45 * pow(10, -6));

Note: I cheated a bit and used atoi from stdlib.h for spaces sake

Compile: gcc atofE.c -lm -o atofE

*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSTR 10

double custom_atof(char s[])
{
    char storage[MAXSTR], storage2[MAXSTR]; /* storage for the float and int strings */
    int power_val, sign, i = 0, j = 0, k = 0;
    int exponent_convert = 0;
    double val, power;
    float result;

    if (strlen(s) > MAXSTR)
        return -1;

    /* split the signed exponent to convert "float string" to float variable */
    while (s[i] != '\0')
    {
        /* signed exponent detected, get needed variables*/
        if (s[i] == 'e' || s[i] == 'E')
        {
            exponent_convert = 1;

            storage[i] = '\0'; /* NULL that E */
            s[i] = '\0';

            /* get integer for power of x value */
            while (s[++i] != '\0')
            {
                storage2[j++] = s[i];
            }
            storage2[j] = '\0';
            /* convert to integer */
            power_val = atoi(storage2);

            break;
        }
        /* store the float string only */
        storage[i] = s[i];
        i++;
    }

    /* convert float section of the string into a float */
    for (k; isspace(s[k]); k++) { ; }
    sign = (s[k] == '-') ? -1 : 1;
    if (s[k] == '+' || s[k] == '-')
        k++;
    for (val = 0.0; isdigit(s[k]); k++)
        val = 10.0 * val + (s[k] - '0');
    if (s[k] == '.')
        k++;
    for (power = 1.0; isdigit(s[k]); k++) {
        val = 10.0 * val + (s[k] - '0');
        power *= 10.0;
    }

    result = sign * val / power;

    if (exponent_convert = 1)
    {
        /* convert power str to integer */
        power_val = atoi(storage2);
        /* return conversion */
        return (result * pow(10, power_val));
    }
    else
        /* just return float */
        return result;
}

int main()
{
    char s[]= "123.45E-6";

    printf("%.8f\n", custom_atof(s));
}

