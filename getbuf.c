/* 一个有缓存的接受字符的函数  */
#include <stdio.h>
#define BUFSIZE 100

int buf[BUFSIZE];
int bp=0;

int getch(void){
	return (bp>0) ? buf[--bp] : getchar();
}

void ungetch(int c){
	if(bp<BUFSIZE)
		buf[bp++]=c;
	else
		printf("sdsdfs");
}

void ungets(char s[]){
	void ungetch(int c);

	for(int i=0;s[i]!='\0';i++)
		ungetch(s[i]);
}

