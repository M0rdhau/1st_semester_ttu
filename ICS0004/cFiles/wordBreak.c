#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include <stdarg.h>

char *CreateRandomSentence(int nWords, ...)
{
	va_list indic;
	va_start(indic, nWords);
	int nChars = 0, j =0;
	for (int i = 0; i < nWords; i++, nChars += va_arg(indic, int) +1);
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char *pResult = (char *)malloc(nChars);
	va_start(indic, nWords);
	for (int i = 0; i < nWords; i++)
	{
		int nWord = va_arg(indic, int);
		for(int k =0; k < nWord; k++, *(pResult + j++) = alphabet[rand() % 26]);
			*(pResult + j++) = ' ';
	}
	*(pResult + nChars -1) = 0;
	return pResult;
}

char **SentenceSplit(char *c, int *numWords)
{
	if(c == 0 || numWords == 0)
	{
		return 0;
	}

	char **sTable = (char **)malloc(*numWords * sizeof(char *));
	int sCursor = 0;//sentence cursor
	for (int i = 0; i < *numWords; i++)
	{
		int letNum = 0;
		while(*(c + sCursor) != ' ' && *(c + sCursor) != 0)
		{
			letNum++;
			sCursor++;
		}
		sCursor -= letNum;
		*(sTable + i) = (char *)malloc(letNum);
		for (int j = 0; j < letNum; j++)
		{
			*(*(sTable + i) + j) = *(c + sCursor);
			sCursor++;
		}
		sCursor += 1;
	}

	return sTable;
	//need to convert words into pointers - can iterate over them
	//and store numChars for each word, use malloc,
	//then go back and put the chars in the correct places.
	//god bless
}

int main(int argc, char const *argv[])
{
	int *numWords =(int *)malloc(sizeof(int));
	*numWords = 5;
	printf("%d\n", *numWords);
	char *c = CreateRandomSentence(*numWords, 5, 4, 6);
	printf("%s\n", c);
	char **cTable = SentenceSplit(c, numWords);
	for(int i = 0; i < *numWords; i++)
	{
		printf("%s\n", *(cTable + i));
	}
	return 0;
}