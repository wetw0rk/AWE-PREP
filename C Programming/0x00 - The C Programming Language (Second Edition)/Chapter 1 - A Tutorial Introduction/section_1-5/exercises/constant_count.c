#include <stdio.h>

int main()
{ // delcare vars as zero or get a strange error
	int c, nl=0, tl=0, bl=0;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n')	// newline
			++nl;
		if (c == '\t')	// tabs
			++tl;
		if (c == ' ')		// spaces
			++bl;
	}

	printf("Newlines (\\n): %d, Tabs (\\t): %d, Spaces (' '): %d\n",
			nl, tl, bl);

}
