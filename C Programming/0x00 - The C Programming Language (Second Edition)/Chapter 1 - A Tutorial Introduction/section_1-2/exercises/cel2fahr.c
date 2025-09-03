#include <stdio.h>

/*
print Fahrenheit-Celsius table
for fahr = 0, 20 ..., 300
Equation: C = (5/9)(F-32)
*/

int main()
{
	int lower, upper, step;
	float fahr, celsius;

	lower	= 0;		// lower limit of temperature table
	upper	= 300;	// upper limit
	step	= 20;		// step size

	printf("+---------+------------+\n");
	printf("| Celsius | Fahrenheit |\n");
	printf("+---------+------------+\n");

	celsius = lower;
	while (celsius <= upper)
	{
		fahr = (celsius * 9/5) + 32.0;
		printf("| %6.0f %2c %9.1f  |\n", celsius, fahr, '|');
		printf("+----------------------+\n");
		celsius = celsius + step;
	}
}
