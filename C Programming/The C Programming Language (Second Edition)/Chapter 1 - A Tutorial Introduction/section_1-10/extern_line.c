#include <stdio.h>

#define MAXLINE 1000

char longest[MAXLINE];
char line[MAXLINE];
int max;

int getline(void);
void copy(void);

/* print longest input line; specialized version */
int main()
{
/*	extern char longest[]; */
/*	extern int max; */
	int len;

	max = 0;
	while ((len = getline()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0)
		printf("%s", longest);

	return(0);
}

/* getline: specialized version */
int getline(void)
{
/*	extern char line[]; */
	int c, i;

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i;
}

/* copy: specialized version */
void copy(void)
{
/*	extern char line[], longest[]; */
	int i = 0;

	while ((longest[i] = line[i]) != '\0')
		++i;
}
