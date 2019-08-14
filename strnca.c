#include <stdio.h>

char *strnca(char *s, char *ct,int n){
	int i=0;
	int j=0;
	while(s[i++]!='\0')
		;
	--i;
	while(j<n&&(s[i++]=ct[j++]))
		;
	s[i]='\0';
	return s;
}

int strncm(char *s, char *t, int n){
	n--;
	for(;(*s == *t)&&(n--);s++,t++)
		if(*s=='\0' )
			return 0;
	return *s - *t;
}
int main(void){
	char s[]="dsfs";
	char ct[]="dsfsdfs";
	printf("%d%d%d\n",strncm(s,ct,2),strncm(s,ct,6),strncm(s,ct,4));
}
