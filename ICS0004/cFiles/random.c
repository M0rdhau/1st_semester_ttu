#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i = 0;
	while(i < 50)
	{
		int num = rand();
		if(num < 500)
		{
			printf("%d \n", num);
		}
		i = i + 1;
	}
	return 0;
}