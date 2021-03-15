#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define SUCCESS 0
#define MEM_NEG 1
#define MEM_ZERO 2
#define MEM_TOO_BIG 3
#define POINTER_ZERO 4
#define ARR_EMPTY 5

int *CreateRandomArray(int n, int lower, int upper)
{
	if(n <= 0 || lower >= upper)
	{
		return 0;
	}
	int *pResult = (int *) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		*(pResult + i) = lower + rand() %(upper - lower + 1);
	}
	return pResult;
}

int CheckSum(int *arr, int len, int *error)
{
	if(len == 0)
	{
		*error = ARR_EMPTY;
		return 0;
	}
	else if(arr == 0)
	{
		*error = POINTER_ZERO;
		return 0;
	}
	int sum = 0;

	for (int i = 0; i < len; i++)
	{
		if(*(arr + i) > 1000)
		{
			*error = MEM_TOO_BIG;
			return 0;
		}
		else if(*(arr + i) == 0)
		{
			*error = MEM_ZERO;
			return 0;
		}
		else if(*(arr + i) < 0)
		{
			*error = MEM_NEG;
			return 0;
		}
		sum += *(arr + i);
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	int *error = (int *) malloc(sizeof(int));
	for (int i = 0; i < 15; i++)
	{
		int n = CheckSum(CreateRandomArray(i, i, 15), i, error);
		if(n != 0)
		{
			printf("%d is the total sum \n", n);
		}
		else
		{
			switch(*error)
			{
				case 1: printf("Array Member is negative\n");
						break;
				case 2: printf("Array Member is zero\n");
						break;
				case 3: printf("Array Member is out of bounds\n");
						break;
				case 4: printf("Array doesn't exist\n");
						break;
				case 5: printf("Array is empty\n");
						break;
			}
		}
	}
	return 0;
}