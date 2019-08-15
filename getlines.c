#include <stdio.h>

int getLine(char *oneline,int maxl){
	int c;
	char *ptr;
	ptr=oneline;
	while(--maxl>0&&(c=getchar())!=EOF&&c!='\n')
		*oneline++=c;
	if(c=='\n')
		*oneline++=c;
	*oneline='\0';
	return oneline-ptr;
}

