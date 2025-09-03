#include <stdio.h>

#define IN	1 // inside a word
#define OUT	0 // outside a word

int main()
{
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF)
	{
		// not in a word
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		// in a word
		else if (state == OUT)
		{
			state = IN;
			putchar('\n');	// if we are at the start of new word
			putchar(c);			// start it in a newline
		}
		else
		{
			putchar(c);
		}
	}
}
