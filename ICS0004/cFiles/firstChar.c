#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x;
	char line[81];
	printf("Type in the text, please: ");
	fgets(line, 81, stdin);
	x = line[0];
	if(x >= '0' && x <= '9')
	{
		printf("text starts with a digit \n");
	}
	else if(x >= 'A' && x <= 'Z')
	{
		printf("text starts with an uppercase \n");
	}
	else if(x >= 'a' && x <= 'z')
	{
		printf("text starts with a lowercase \n");
	}
	else
	{
		printf("text starts with an unidentified character\n");
	}
	return 0;
}