#include <stdio.h>
#define MAXL 1000

int getLine(char oneline[],int maxl);
void copyline(char from[],char to[]);
int modifyline(char oneline[],int cl);
void reverse(char from[],int cl,char to[]);  

int main(void){
	char to[MAXL];
	char oneline[MAXL];
	int cl;
	while((cl=getLine(oneline,MAXL))>0){
		reverse(oneline,cl,to);
		printf("此行长为%d %s",cl,to);
}
}
                 
int getLine(char oneline[],int maxl){
	int c;
	int i;
	for(i=0;i<maxl-1&&(c=getchar())!=EOF&&c!='\n';i++)
		oneline[i]=c;
	if(c=='\n'){
		oneline[i]='\n';
		i++;}
	oneline[i]='\0';
	return i;
}
                        
void copyline(char from[],char to[]){
	int i=0;
	while(from[i]!='\0'){
		to[i]=from[i];
		i++;
	}
}
                       
int modifyline(char oneline[],int cl){
	
	while(cl>0&&(oneline[cl-1]==' '||oneline[cl-1]=='\t'||oneline[cl-1]=='\n'||oneline[cl-1]=='\0')){
		oneline[cl-1]='\0';
		cl--;
	}
	oneline[cl]='\n';
	return cl;
	
}
void reverse(char from[],int cl,char to[]){
	int i=0;
	while(cl>0){
		if(from[cl-1]=='\n'){
			to[cl-1]='\n';
			to[cl]='\0';
			i--;
		}
		else{
		        to[i]=from[cl-1];
		}
		i++;
		cl--;
	}
	
}

