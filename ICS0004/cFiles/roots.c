#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	double a,b,c, d, solution;
	char line[81];
	printf("Type 'a' parameter: ");
	fgets(line, 81, stdin);
	a = atoi(line);
	if(a == 0)
	{
		printf("a is 0, function is not quadratic");
		return 0;
	}
	printf("Type 'b' parameter: ");
	fgets(line, 81, stdin);
	b = atoi(line);
	printf("Type 'c' parameter: ");
	fgets(line, 81, stdin);
	c = atoi(line);
	d = b*b - 4*a*c;
	if(d > 0)
	{
		solution = sqrt(d);
		printf("solutions are %lf and %lf \n", solution, -1*solution);
	}
	else if(d == 0)
	{
		solution = sqrt(d);
		printf("solutions is %lf \n", solution);
	}
	else if(d < 0)
	{
		printf("the equation has no solution \n");
	}
	return 0;
}