/*  一个收录操作数和运算符的函数  */
#include <ctype.h>
#include <stdio.h>
#define NUMBER 0
#define G (bf!=-2) ? bf : getch()
int getch(void);
void ungetch(int);

int getop(char s[]){
	int i;
	int c,c2;
	static int bf=-2;
	while((c=s[0]=G)==' '|| c=='\t')
		bf=-2;
	bf=-2;
	s[1]='\0';
	if(!isdigit(c) && c!='.'&&c!='+'&&c!='-')
		return c;	//not a number
	i=0;
	if((c=='+'||c=='-')&&(!isdigit(c2=G))){
		bf=c2;
		return c;
	}
	if(c=='+' ||c=='-'){
		bf=-2;
		s[++i]=c2;
		c=c2;
	}
	if(isdigit(c)){
		while(isdigit(s[++i]=c=G))
		bf=-2;
		bf=-2;
	}
	if(c=='.'){
		while(isdigit(s[++i]=c=G))
		bf=-2;
		bf=-2;
	}
	s[i]='\0';
	bf=c;
	return 0;
}

