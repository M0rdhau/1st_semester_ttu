#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int Rand[50];
	int i = 0;
	int max = 0;
	while(i < 50)
	{
		Rand[i] = rand();
		printf("current random is %d, number%d\n", Rand[i], i);
		if(Rand[i] > max)
		{
			max = Rand[i];
		}
		i++;
	}
	printf("Maximum is %d\n", max);
	max = 0;
	return 0;
}