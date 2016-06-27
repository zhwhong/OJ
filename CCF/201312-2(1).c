#include <stdio.h>
#include <stdlib.h>

int deal(char *str);
void print(char *str, int sum);

int main()
{
	char s[30];
	char *str = s;
	scanf("%s",str);
    deal(str);
	return 0;
}

int deal(char *str)
{
	int i, sum = 0;
	for(i = 0; i < 13; i++){
		char c = *(str+i);
		switch(i){
			case 0: 
				if(c < '0' || c > '9')
					return 0;
				sum += (c - '0');
				break;
			case 2: case 3: case 4: 
				if(c < '0' || c > '9')
					return 0;
				sum += i * (c - '0');
				break;
			case 6: case 7: case 8: case 9: case 10:
				if(c < '0' || c > '9')
					return 0;
				sum += (i - 1) * (c - '0');
				break;
			case 1: case 5: case 11:
				if(c != '-')
					return 0;
				break;
			case 12:
				sum %= 11;
				if(sum == 10){
					if(c == 'X'){
						printf("Right\n");
						return 1;
					}
					print(str,sum);
					return 0;
				}
				else{
					if(sum == (c - '0')){
						printf("Right\n");
						return 1;
					}
					print(str,sum);
					return 0;
				}
		}
	}
	return 0;
}

void print(char *str, int sum)
{
	int i;
	char c;
	for(i = 0; i < 12; i++){
		c = *(str+i);
		printf("%c",c);
	}
	if(sum == 10)
		printf("X\n");
	else
		printf("%c\n",sum+'0');
}
