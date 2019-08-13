#include <stdio.h>

void itoa(int , char[]);

int main(void){
	char s[100];
	itoa(-2315235,s);
	printf("%s\n",s);
}

void itoa(int n, char s[]){
	static int i=0;
	if(n<0){
		s[i++]='-';
		n=-n;
	}
	if(n/10)
		itoa(n/10,s);
	s[i++]=n%10+'0';
	s[i]='\0';
}
