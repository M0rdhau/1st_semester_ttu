#include <stdio.h>
#include <stdlib.h>

#define SPACE ' '

char Buf1[81], Buf2[81];

void rewrite()
{
	int j = 0;
	for (int i = 0; i < 81 && Buf1[i] != 0; i++)
	{
		if(!(Buf1[i] == SPACE && Buf1[i-1] == SPACE)){
			Buf2[j] = Buf1[i];
			j++;
		}
	}
	Buf2[j] = '\0';
}

int main(int argc, char const *argv[])
{
	printf("Type the number: ");
	fgets(Buf1, 81, stdin);
	rewrite();
	printf("Uncorrected text: \n%s", Buf1);
	printf("Corrected text: \n%s\n", Buf2);
	return 0;
}