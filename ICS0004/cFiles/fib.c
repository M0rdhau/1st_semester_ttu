#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int fib[20];
	int i = 2;
	fib[0] = fib[1] = 1;
	printf("1\n");
	printf("1\n");
	while(i < 20)
	{
		fib[i] = fib[i-1] + fib[i -2];
		printf("%d\n", fib[i]);
		i++;
	}
	return 0;
}