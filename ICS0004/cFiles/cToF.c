#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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



double converter(double temp, char fOrC)
{
	if(fOrC == 'F' || fOrC == 'f')
	{
		return (temp -32)*5/9;
	}
	else if(fOrC == 'C' || fOrC == 'c')
	{
		return (temp*9)/5 + 32;
	}
	else
	{
		return NAN;
	}
}

int main(int argc, char const *argv[])
{
	float x;
	char line[81];
	printf("Type the number: ");
	fgets(line, 81, stdin);
	x = atof(line);
	printf("\nType the system: ");
	char c = getche();
	if(isnan(converter(x, c)))
	{
		printf("\nNo Solution\n");
	}else{
		printf("\nSolution is %lf\n", converter(x, c));
	}
	return 0;
}