#include <stdio.h>
#include <string.h>
#define MAXL 1000

int getLine(char * , int);
extern double atof(char []);

int main(int argc , char *argv[]){
	int n,count;
	char lines[MAXL];
	char linesp[500][MAXL];
	count=0;
	if(argc==1)
		n=10;
	else if(argc==2 && argv[1][0]=='-')
		n=(int)atof(++argv[1]);
	else{
		printf("error arg\n");
		return 1;
	}
	while(getLine(lines,MAXL)>0){
		strcpy( linesp[count],lines);
		count++;
	}
	for(int j=count-n;j<count;j++)
		printf("%s",linesp[j]);
}
