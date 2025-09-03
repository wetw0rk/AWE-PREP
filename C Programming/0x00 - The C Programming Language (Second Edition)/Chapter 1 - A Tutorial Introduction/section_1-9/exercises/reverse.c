/* write a function that reverses the character string s */

#include <stdio.h>

void reverse_string(char str[], int len)
{
	char temp_array[len];
	int i, j = 0;

	for (i = (len-1); i >= 0; i--)
	{
		temp_array[j] = str[i];
		j++;

	}
	temp_array[len] = '\0';	// temp_array now holds the reversed character string

	j = 0;
	for (i = 0; i < len; i++)
	{
		str[i] = temp_array[j];
		j++;
	}
	str[len] = '\0';
}

int main() {

	char s[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	reverse_string(s, 26);
	printf("%s\n", s);
}
