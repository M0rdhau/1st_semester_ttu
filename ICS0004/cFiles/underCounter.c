#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int x =0, i = 0;
	char line[81];
	char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
	printf("Type the string: ");
	fgets(line, 81, stdin);
	while(i < 81)
	{
		if(line[i] == 0)
		{
			break;
		}
		int j = 0;
		while(j < 6)
		{
			if(line[i] == vowels[j])
			{
				x++;
				break;
			}
			j++;
		}
		i++;
	}
	printf("number of lowercase vowels: %d\n", x);
	return 0;
}