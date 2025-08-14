#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c, numchars, total;
	int j, i = 0, line;

	printf("Please enter 10 words\n");
	while ((c = getchar()) != EOF)
	{
		numchars++;

		if (c == '\n')
		{
			total = (numchars-1);
			numchars = 0;
			i++;

			// print the bar graph thing..
			printf(" {%d} ", total);
			for (j = 0; j < total; j++)
			{
				printf("%c", '-');
			}
		}
		if (i == 9)
		{
			exit(0);
		}
		putchar(c);
	}
}
