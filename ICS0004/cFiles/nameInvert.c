#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

char *CreateRandomName(int n1, int n2)
{//n1 firstname n2 lastname
	if(n1 <= 0 || n2 <= 0)
	{
		return 0;
	}

	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char *pResult = (char *)malloc(n1 + n2 + 2);
	for (int i = 0; i < n1; i++)	
	{
		*(pResult + i) = alphabet[rand()%26];
	}
	*pResult = toupper(*pResult);
	*(pResult + n1) = ' ';
	for (int i = 0; i < n2; i++)
	{
		*(pResult + n1 + 1 + i) = alphabet[rand()%26];
	}
	*(pResult + n1 + 1) = toupper(*(pResult + n1 + 1));
	*(pResult + n1 + n2 + 1) = 0;
	return pResult;
}

char *NameInvert(char *name)
{
	int fNameLen = 0;
	int lNameLen = 0;
	int size = 0;
	bool n = false;
	while(*(name + size) != '\0')
	{
		if(*(name + size) == ' ')
		{
			n = true;
			size++;
		}
		if(n){
			lNameLen++;
		}else{
			fNameLen++;
		}
		size++;
	}
	char *toRet = (char *)malloc(size+2);
	for(int i = 0; i < lNameLen; i++)
	{
		*(toRet + i) = *(name + fNameLen + 1 + i);
	}
	*(toRet + lNameLen) = ',';
	*(toRet + lNameLen + 1) = ' ';
	for(int i = 0; i < fNameLen; i++)
	{
		*(toRet + fNameLen + 2 + i) = *(name + i);
	}
	*(toRet + size + 1) = '\0';
	return toRet;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; i++)
	{
		char *c = CreateRandomName(5, 5);
		printf("%s - ", c);
		printf("%s\n", NameInvert(c));
		free(c);
		/* code */
	}
	return 0;
}