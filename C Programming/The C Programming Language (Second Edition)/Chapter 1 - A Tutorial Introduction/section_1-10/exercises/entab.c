/*
write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as
for detab. when either a tab or a single blank would suffice to reach a tab
stop, which should be given preference?
*/

#include <stdio.h>

int main()
{
	int ns = 0;
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' && ns != 7) {
			ns++;
			if (ns == 7) {
				putchar('\t');
				ns = 0;
			}
		}
		else {
			putchar(c);
		}
	}
}
