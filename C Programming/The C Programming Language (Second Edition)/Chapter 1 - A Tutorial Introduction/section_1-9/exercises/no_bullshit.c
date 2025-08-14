/* write a program to remove trailing blanks and tabs from each line of input,
 * and try to delete entirely blank lines */

#include <stdio.h>
#define MAXLEN 1000

int lineget(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		if (c != '\t' && c != ' ') {
			line[i] = c;
		}
		else {
			--i;
		}
	}
	if (c == '\n' && c-1 != ' ') {
		line[i] = c;
		++i;
		line[i] = '\0';
	}
	else
	{
		i = 0;
	}

	return i;
}

int main()
{
	char string_array[MAXLEN];
	int len;

	while ((len = lineget(string_array, MAXLEN)) > 0) {
		if (len > 1) {
			printf("{%d} %s", len, string_array);
		}
	}
}
