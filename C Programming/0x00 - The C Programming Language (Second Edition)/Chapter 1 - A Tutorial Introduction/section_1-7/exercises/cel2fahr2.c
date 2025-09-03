#include <stdio.h>


float celsius2fahrenheit(float celsius)
{
	float fahr;

	fahr = (celsius * 9/5) + 32.0;

	return fahr;
}

int main()
{
	int lower, upper, step;
	float fahr, celsius;

	lower = 0;
	upper = 300;
	step  = 20;


	celsius = lower;
	while (celsius <= upper)
	{
		fahr = celsius2fahrenheit(celsius);
		printf("celsius: %.0f, fahrenheit: %.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return(0);
}
