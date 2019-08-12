/*  一个收录操作数和运算符的函数  */
#include <ctype.h>
#include <stdio.h>
#define NUMBER 0

int getch(void);
void ungetch(int);

int getop(char s[]){
	int i;
	int c,c2;
	while((c=s[0]=getch())==' '|| c=='\t')
		;
	s[1]='\0';
	if(!isdigit(c) && c!='.'&&c!='+'&&c!='-')
		return c;	//not a number
	i=0;
	if((c=='+'||c=='-')&&(!isdigit(c2=getch()))){
		ungetch(c2);
		return c;
	}
	if(c=='+' ||c=='-'){
		s[++i]=c2;
		c=c2;
	}
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()));
	if(c=='.')
		while(isdigit(s[++i]=c=getch()));
	s[i]='\0';
	ungetch(c);
	return 0;
}


