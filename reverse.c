#include <stdio.h>
#include <string.h>

int reverse(char[],int,int);

int main(void){
	char s[]="a test";
	reverse(s,0,strlen(s)-1);
	printf("%s\n",s);
}

int reverse(char s[],int i, int j){
	int a;
	if(i>=j)
		return 0;
	a=s[i];
	s[i]=s[j];
	s[j]=a;
	reverse(s,i+1,j-1);
	return 1;
}
