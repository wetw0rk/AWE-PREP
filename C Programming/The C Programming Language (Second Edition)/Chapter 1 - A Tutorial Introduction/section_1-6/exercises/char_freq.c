#include <stdio.h>

int main()
{
	char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int i, j, c, alphanum[25]={0};

	while ((c = getchar()) != EOF)
	{
		if (c == 'a' || c == 'A') { alphanum[0]++; }
		if (c == 'b' || c == 'B') { alphanum[1]++; }
		if (c == 'c' || c == 'C') { alphanum[2]++; }
		if (c == 'd' || c == 'D') { alphanum[3]++; }
		if (c == 'e' || c == 'E') { alphanum[4]++; }
		if (c == 'f' || c == 'F') { alphanum[5]++; }
		if (c == 'g' || c == 'G') { alphanum[6]++; }
		if (c == 'h' || c == 'H') { alphanum[7]++; }
		if (c == 'i' || c == 'I') { alphanum[8]++; }
		if (c == 'j' || c == 'J') { alphanum[9]++; }
		if (c == 'k' || c == 'K') { alphanum[10]++; }
		if (c == 'l' || c == 'L') { alphanum[11]++; }
		if (c == 'm' || c == 'M') { alphanum[12]++; }
		if (c == 'n' || c == 'N') { alphanum[13]++; }
		if (c == 'o' || c == 'O') { alphanum[14]++; }
		if (c == 'p' || c == 'P') { alphanum[15]++; }
		if (c == 'q' || c == 'Q') { alphanum[16]++; }
		if (c == 'r' || c == 'R') { alphanum[17]++; }
		if (c == 's' || c == 'S') { alphanum[18]++; }
		if (c == 't' || c == 'T') { alphanum[19]++; }
		if (c == 'u' || c == 'U') { alphanum[20]++; }
		if (c == 'v' || c == 'V') { alphanum[21]++; }
		if (c == 'w' || c == 'W') { alphanum[22]++; }
		if (c == 'x' || c == 'X') { alphanum[23]++; }
		if (c == 'y' || c == 'Y') { alphanum[24]++; }
		if (c == 'z' || c == 'Z') { alphanum[25]++; }
	}

	for (i = 0; i < 26; i++)
	{
		printf("[ %c ] ", alphabet[i]);
		for (j = 0; j < alphanum[i]; j++)
		{
			printf("-");
		}
		putchar('\n');
	}
}
