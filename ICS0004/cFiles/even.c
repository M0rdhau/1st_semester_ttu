#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x;
	char line[81];
	printf("Type the number: \n");
	fgets(line, 81, stdin);
	x = atoi(line);
	if(x == 0)
	{
		printf("The number is zero\n");
	}
	else if(x % 2 == 0)
	{
		printf("%d is even\n", x);
	}
	else
	{
		printf("%d is odd\n", x);
	}
	return 0;
}