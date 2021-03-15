#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x =0, i = 0;
	char line[81];
	printf("Type the first: ");
	fgets(line, 81, stdin);
	while(i < 79)
	{
		char c = line[i];
		if(c == 0)
		{
			break;
		}
		if((c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z') && c != 10)
		{
			printf("illegal input\n");
			return 0;
		}
		else if(c == 'a' || c == 'A')
		{
			x++;
		}
		i++;
	}
	printf("number of A's - %d\n", x);
	return 0;
}