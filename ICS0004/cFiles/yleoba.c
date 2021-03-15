#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int i1 = 10, i2=300, i3 = -10;
	char c1 = (char)i1;
	char c2 = (char)i2;
	unsigned char uc = (unsigned char)i3;
	printf("int: %d, char: %hhu \n",i1, c1);
	printf("int: %d, char: %hhu \n",i2, c2);
	printf("int: %d, char: %hhu \n",i3, uc);
	return 0;
}