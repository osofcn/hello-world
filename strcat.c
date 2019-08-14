#include <stdio.h>
#include <string.h>

char * strcatt(char *s, char *t){
	static char st[100];
	int i=0;
	while(st[i++]=*s++)
		;
	i--;
	while(st[i++]=*t++)
		;
	return st;
}


int main(void){
	char s[]="you are";
	char t[]=" beautiful";
	printf("%s\n", strcatt(s,t));
	return 0;
}


