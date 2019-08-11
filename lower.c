#include <stdio.h>

char lower(char);
int main(void){
	char c;
	scanf("%c",&c);
	printf("%c\n", lower(c));
}

char lower(char c){
	return (c>='A'&&c<='Z') ? c-'A'+'a':c;
}
