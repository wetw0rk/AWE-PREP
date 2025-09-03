/* use the function from the prevous program to reverse input a line at a time */

#include <stdio.h>
#define  MAXLINE 1000

// reverse a character array, using a temp array
void reverse_string(char str[], int len)
{
	char temp_array[len];
	int i, j = 0;

	for (i = (len-1); i >= 0; i--) {
		temp_array[j] = str[i];
		j++;
	}
	temp_array[len] = '\0';

	for (i = 0; i < len; i++) {
		str[i] = temp_array[i];
	}
	str[len] = '\0';
}

// read a line into array into s, and return length
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}

int main()
{
	char character_str[MAXLINE];
	int len;

	while ((len = get_line(character_str, MAXLINE)) > 0) {
		reverse_string(character_str, len);
		printf("%s\n", character_str);
	}

	return(0);
}
