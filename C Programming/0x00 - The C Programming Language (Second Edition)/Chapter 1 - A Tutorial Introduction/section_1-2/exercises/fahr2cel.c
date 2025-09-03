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

	printf("+------------+---------+\n");
	printf("| Fahrenheit | Celsius |\n");
	printf("+------------+---------+\n");
	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr-32.0);
		printf("| %6.0f %5c %6.1f  |\n", fahr, celsius, '|');
		printf("+----------------------+\n");
		fahr = fahr + step;
	}
}
