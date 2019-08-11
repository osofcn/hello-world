#include <stdio.h>
#include <math.h>
#include <string.h>

void itoa(int n, char s[],int,int);
void reverse(char []);

int main(void){
	int n=pow(2,5);
	char s[100];
	itoa(n,s,16,15);
	printf("%s\n",s);
}

void itoa(int n, char s[],int b,int a){
	int i=0;
	char sign='+';
	char iword[]="0123456789abcdef";
	if(n<0)
		sign='-';
	do
	{
		s[i]=iword[abs(n%b)];
		i++;
	}while(abs(n/=b)>0);
	if(sign=='-')
		s[i++]='-';
	while(i<a)
		s[i++]=' ';
	s[i]='\0';
	reverse(s);
}

void reverse(char s[]){
	int i,j;
	char c;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
		c=s[i],s[i]=s[j],s[j]=c;
}

