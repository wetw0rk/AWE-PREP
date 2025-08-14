/*
write a program detab that replaces tabs in the input with the proper number of blanks
by the minimum number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. should n be a variable or symbolic parameter?
*/

#include <stdio.h>

#define TAB "    "

int main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		/* test */
		if (c == '\t')
			printf("%s", TAB);
		else
			putchar(c);
	}

	return(0);
}
