#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCCESS 0
#define PARAMETER_TOO_LARGE 1
#define PARAMETER_TOO_SMALL 2
int error_code = SUCCESS;

int RandVal[100];

int GetRandArray(int arrLen){
	int maxVal = 0;
	if(arrLen <= 0){
		error_code = PARAMETER_TOO_SMALL;
		return maxVal;
	}else if(arrLen > 100){
		error_code = PARAMETER_TOO_LARGE;
		return maxVal;
	}

	int i;
	for(i = 0; i < arrLen; i++){
		RandVal[i] = rand();
		if(RandVal[i] > maxVal) maxVal = RandVal[i];
	}

	return maxVal;
}

int main(int argc, char const *argv[]){
	int x;
	char line[81];
	printf("Type the number: ");
	fgets(line, 81, stdin);
	x = atoi(line);
	int maxRand = GetRandArray(x);
	printf("\n");
	if (error_code == SUCCESS)
	{
		printf("%d is the max value\n", maxRand);
	}else if(error_code == PARAMETER_TOO_LARGE){
		printf("parameter is too large\n");
	}else if(error_code == PARAMETER_TOO_SMALL){
		printf("parameter is too small\n");
	}else{
		printf("unknown error\n");
	}
	
	return 0;
}