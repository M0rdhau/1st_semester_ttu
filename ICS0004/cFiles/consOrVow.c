#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <ctype.h>


static struct termios old, current;

void initTermios(int echo)
{
	tcgetattr(0, &old);
	current = old;
	current.c_lflag &= ~ICANON;
	if(echo) {
		current.c_lflag |= ECHO;
	} else {
		current.c_lflag &= ~ECHO;
	}
	tcsetattr(0, TCSANOW, &current);
}

void resetTermios(void)
{
	tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo)
{
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

char getch(void)
{
	return getch_(0);
}

char getche(void)
{
	return getch_(1);
}

char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
char consonants[20];
char buf[81];


void calcConsonants(){
	int offset = 0;
	for(int i = 'b'; i <= 'z'; i++){
		for (int j = 0; j < 6; j++)
		{
			// printf("consonant: %c\n", i);
			// printf("vowel: %c\n", vowels[j]);
			if(i == vowels[j]){
				i++;
				offset++;
				break;
			}
		}
		consonants[i - 'b' - offset] = i;
	}
}

void numCons()
{
	int num = 0;
	for (int i = 0; i < 80 && buf[i] != '\0'; ++i)
	{
		for(int j = 0; j < 20; j++){
			if (tolower(buf[i]) == consonants[j])
			{
				num++;
			}
		}
	}
	printf("there are %d consonants\n", num);
}

void numVows()
{
	int num = 0;
	for (int i = 0; i < 80 && buf[i] != '\0'; ++i)
	{
		for(int j = 0; j < 6; j++){
			if (tolower(buf[i]) == vowels[j])
			{
				num++;
			}
		}
	}
	printf("there are %d vowels\n", num);
}

void getText(){
	printf("Type the string: ");
	fgets(buf, 81, stdin);
}

int main(int argc, char const *argv[])
{
	calcConsonants();
	int num = 0;
	printf("v - count vowels\nc - count consonants\nx - exit\n");
	char c = getche();
	printf("\n");
	if(c == 'x' || c == 'X'){
		return 0;
	}else if(c == 'v' || c=='V'){
		getText();
		numVows();
	}else if(c == 'c' || c== 'C'){
		getText();
		numCons();
	}
	return 0;
}