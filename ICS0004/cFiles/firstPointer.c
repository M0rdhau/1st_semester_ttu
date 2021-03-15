#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *CreateRandomString(int n)
{
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz"; 
	char *pResult = (char *)malloc(n+1);
	for (int i = 0; i < n; i++)
	{
		int rnd = rand()%26;
		// printf("%c ", alphabet[rnd]);
		*(pResult+ i)=alphabet[rnd];
		// printf("%c\n", *(pResult+i));
	}	
	*(pResult+n) = 0;
	return pResult;
}

char *Reverse(char * c)
{
	int size = 0;
	while(*(c + size) != '\0')
	{
		size++;
	}
	char *toRet = (char *)malloc(size+1);
	for (int i = 0; i < size; i++)
	{
		*(toRet + i) = *(c + size - i - 1);
	}
	*(toRet + size) = '\0';
	return toRet;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 4; i++)
	{
		char *toRet = CreateRandomString(10);
		printf("%s - ", toRet);
		printf("%s\n", Reverse(toRet));
	}
	return 0;
}
