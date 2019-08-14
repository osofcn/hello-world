#include <stdio.h>
#include <string.h>

int strend(char * s, char * t){
	int c;
	if((c=strlen(s)-strlen(t))<0)
		return 0;
	for(s +=c;*s== *t;s++,t++)
		if(*t=='\0')
			return 1;
	return 0;
}

int main(void){
	char s[]="fwfwwfwe";
	char t[]="fww";
	printf("%d\n",strend(s,t));
}


