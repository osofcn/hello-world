#include <stdio.h>
#include <ctype.h>

int getfloat(float *f){
	int c,sign;
	
	while(!isdigit(c=getch())&&c!=EOF&&c!='+'&&c!='-')
		;
	sign=(c=='-') ? -1 : 1;
	if((c=='+‘ || c=='-') && !isdigit(c=getch())){
	       ungetch((sign==-1) ? '-' : '+');
	       ungetch(c);
