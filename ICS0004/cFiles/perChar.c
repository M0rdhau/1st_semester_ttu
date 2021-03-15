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
	// char c;
	// printf("(getche example) please type a letter: ");
	// c = getche();
	// printf("\nYou typed: %c\n", c);
	// printf("(getch example) please type a letter...");
	// c = getch();
	// printf("\nYou typed: %c\n", c);
	char line[21];
	int i = 0;
	while(i < 20)
	{
		char c = getche();
		if(c == 27){
			break;
		}
		line[i] = c;
		i++;
	}
	line[i] = 0;
	printf("Result is %s\n", line);
	return 0;
}