/*  一个收录操作数和运算符的函数  */
#include <ctype.h>
#include <stdio.h>
#define NUMBER 0

int getch(void);
void ungetch(int);

int getop(char s[]){
	int i;
	int c;
	while((c=s[0]=getch())==' '|| c=='\t')
		;
	s[1]='\0';
	if(!isdigit(c) && c!='.')
		return c;            //not a number
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()));
	if(c=='.')
		while(isdigit(s[++i]=c=getch()));
	s[i]='\0';
	if(c!=EOF)
		ungetch(c);
	return 0;
}


