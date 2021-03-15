#include <stdio.h>

int MaxOfThree(int a, int b, int c)
{
	int bigger = 0;
	int biggest = 0;
	if(a > b)
	{
		bigger = a;
	}
	else
	{
		bigger = b;
	}

	if(bigger > c)
	{
		biggest = bigger;
	}
	else
	{
		biggest = c;
	}
	return biggest;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", MaxOfThree(1, 2, 3));
	printf("%d\n", MaxOfThree(3, 2, 1));
	printf("%d\n", MaxOfThree(1, 3, 2));
	printf("%d\n", MaxOfThree(2, 2, 3));
	printf("%d\n", MaxOfThree(2, 2, 2));
	return 0;
}