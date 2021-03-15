#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

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

int main(int argc, char const *argv[])
{
	int counters[6] = {0,0,0,0,0,0};
	char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
	while(1){
		char c = getche();
		if(c == 27){
			printf("\n");
			break;
		}
		int i = 0;
		while(i < 6)
		{
			if(c == vowels[i])
			{
				counters[i]++;
			}
			i++;
		}
	}
	int i = 0;
	while(i < 6)
	{
		printf("%c: %d\n", vowels[i], counters[i]);
		i++;
	}
	return 0;
}