#include <stdio.h>
#include <string.h>

void escape(char[],char[]);
void escape2(char[],char[]);

int main(void){
	char s[100]="sfdsfsf";
	char t[]="dd\\tdd\\n";
	escape2(s,t);
	printf("%s\n", s);
}

void escape(char s[],char t[]){
	int i=strlen(s);
	int j;
	for(int j=0;j<strlen(t);j++){
		switch(t[j]){
			case '\t' :
				s[i++]='\\';
                                s[i++]='t';
				break;
			case '\n' :
				s[i++]='\\';
				s[i++]='n';
				break;
			default :
				s[i++]=t[j];
				break;
			}
	}
	s[i]='\0';
}

void escape2(char s[],char t[]){
	int i=strlen(s);
	int j;
	for(int j=0;j<strlen(t);j++){
		if(t[j]=='\\'){
			switch(t[j+1]){
				case 't' :
					s[i++]='\t';
					j++;
					break;
				case 'n' :
					s[i++]='\n';
					j++;
					break;
				default :
					s[i++]='\\';
					break;
			}
			}
		else{
			s[i++]=t[j];
		}
	}
	s[i]='\0';
}

