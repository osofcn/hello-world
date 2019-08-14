#include <stdio.h>

char *strncp(char *s,char *ct,int n){
	int i;
	char *ptr=s;
	for(i=0;i<n&&(*s++=*ct++);i++)
		;
	if(*--ct)
		*s='\0';
	return ptr;
}

int main(void){
	char s[100];
	char ct[]="dfsdf";
	printf("%s",strncp(s,ct,8));
}
