#include <stdio.h>
#include <stdlib.h>

#define VARSKV '*'
#define PLIUSI '+'
#define MINUSI '-'

int main(int argc, char const *argv[])
{
	char Table[5][5];
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j ++){
			if(j == i){
				printf("%c ", VARSKV);
			}else if(j > i){
				printf("%c ", PLIUSI);
			}else{
				printf("%c ", MINUSI);
			}
		}
		printf("\n");
	}
	return 0;
}