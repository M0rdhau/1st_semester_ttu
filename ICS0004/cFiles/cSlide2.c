#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x,y;
	char line[81];
	printf("Type the first: ");
	fgets(line, 81, stdin);
	x = atoi(line);
	printf("Type the second: ");
	fgets(line, 81, stdin);
	y = atoi(line);
	if(x>y)
		printf("%d is greater than %d \n", x, y);
	else if(x<y)
		printf("%d is less than %d \n", x, y);
	else
		printf("%d is equal to %d \n", x, y);
	return 0;
}