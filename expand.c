#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char[],char[]);

int main(void){
	char s[50];
	char t[1000];
	scanf("%s",&s);
	expand(s,t);
	printf("%s\n",t);
}

void expand(char s[],char t[]){
	int i=0;
	int j=0;
	t[j]=s[i],j++,i++;
	for(;i<strlen(s);i++){
		if(s[i]=='-'&&(isdigit(s[i-1])&&isdigit(s[i+1])||isupper(s[i-1])&&isupper(s[i+1])||islower(s[i-1])&&islower(s[i+1]))&&(s[i+1]-s[i-1]>1)){
			while((s[i-1]+=1)<s[i+1])
				t[j]=s[i-1],j++;
		}
		else{
			t[j]=s[i];
			j++;
		}
	}
	t[j]='\0';
}
