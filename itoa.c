#include <stdio.h>
#include <math.h>
#include <string.h>

void itoa(int n, char s[],int,int);
void reverse(char []);

int main(void){
	int n=23434252;
	char s[100];
	itoa(n,s,16,15);
	printf("%s\n",s);
}

void itoa(int n, char *s,int b,int a){
	int i=0;
	char sign='+';
	char iword[]="0123456789abcdef";
	char *ptr;
	ptr=s;
	if(n<0)
		sign='-';
	do
	{
		*s++=iword[abs(n%b)];
	}while(abs(n/=b)>0);
	if(sign=='-')
		*s++='-';
	while(s-ptr<a)
		*s++=' ';
	*s='\0';
	reverse(ptr);
}

void reverse(char *s){
	int i,j;
	char c;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
		c=s[i],s[i]=s[j],s[j]=c;
}

