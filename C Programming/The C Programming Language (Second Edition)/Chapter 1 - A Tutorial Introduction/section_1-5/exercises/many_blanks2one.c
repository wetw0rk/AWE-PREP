#include <stdio.h>

int main()
{
	char l = '-';											// this variable will contain the blanks	
	int c;														// this variable will contain the current character

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')										// check if the current character is blank
			if (l != ' ')									// check if the last character was blank
				putchar(c);									// if it wasn't blank output the character
		if (c != ' ')										// check if the character is blank
			putchar(c);										// if not output
		l = c;													// store the character in l (last char)
	}
}
