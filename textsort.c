#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
#define MAXLINES 5000
#define MAXB 10000

extern void qsort(char *v[], int ,int);
int readlines(char *text,char *lineptr[], int);
void writelines(char *lineptr[] , int);
int getLine(char *, int);

int main(void){
	char text[MAXB];
	char *lineptr[MAXLINES];
	int nlines;
	if((nlines=readlines(text, lineptr,MAXLINES))>=0){
        qsort(lineptr,0,nlines-1);	
	writelines(lineptr, nlines);
	return 0;
	}
	else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

int readlines(char *text, char *lineptr[], int maxlines){
	int cl,nlines;
	char tmp[MAXLEN], * curptr;

	nlines=0;
	for(curptr=text;(cl=getLine(tmp, MAXLEN))>0;curptr+=cl+1){
		if(nlines>=maxlines || curptr-text+cl>=MAXB)
			return -1;
		strcpy(curptr, tmp);
		lineptr[nlines++]=curptr;
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	int i;
	
	for(i=0; i<nlines; i++)
		printf("%s",lineptr[i]);
}



