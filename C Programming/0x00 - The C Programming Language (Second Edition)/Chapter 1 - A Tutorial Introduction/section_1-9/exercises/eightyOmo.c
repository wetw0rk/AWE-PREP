/* write a program to print all input lines that are longer than 80 characters */

#include <stdio.h>

#define MAXLEN 1000

int sgetline(char line[], int maxline)
{
	int c, i; // for loop & character

	// initialize i as 0; check that i < max strlen; check if we reached EOF; make sure not a newline
	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
	{
		line[i] = c;	// place character into array
	}
	if (c == '\n')
	{ // if the char is a newline
		line[i] = c;	// go ahead and store it into the array
		++i;		// increment i as this holds string len
	}
	line[i] = '\0';	// add the null terminator (note this is why we increment i)

	return i;	// return the size of the character string
}

int main()
{
	char string[MAXLEN];
	int len;

	while ((len = sgetline(string, MAXLEN)) > 0) {
		if (len > 80) {
			printf("{%d} %s", len, string);
		}
	}

	return(0);
}
