#include <stdio.h>
#include <ctype.h>

extern int getch(void);
extern void ungetch(int);

int getfloat(float *f){
	int c,sign;
	float power;
	
	while(!isdigit(c=getch())&&c!='.'&&c!=EOF&&c!='+'&&c!='-')
		;
	sign=(c=='-') ? -1 : 1;
	if((c=='+' || c=='-') && !isdigit(c=getch())){
	       ungetch(c);
	       return 0;
	}
	if(isdigit(c)){
		for(*f=0.0;isdigit(c); c=getch())
			*f=10 * *f + (c - '0');
	}
	if(c=='.'){
		power=1.0;
		while(isdigit(c=getch())){
			*f=10 * (*f) + (c-'0');
			power *=10;
		}
		*f /=power;
	}
	*f *=sign;
	ungetch(c);
	return c;
}

int main(void){
	float *f;
	int a;
	while((a=getfloat(f))!=EOF){
		if(a!=0)
		printf("%f ",*f);
	}
	return 0;
}
