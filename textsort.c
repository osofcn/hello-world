#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1000
#define MAXLINES 5000
#define MAXB 10000

extern void qsort(void *v[], int ,int,int (*)(void *, void *));
int readlines(char *text,char *lineptr[], int);
void writelines(char *lineptr[] , int);
int getLine(char *, int);
int numcmp(char *, char *);
double atof(char *);
int strvcmp(char *,char *);
int strdcmp(char *,char *);

int main(int argc, char *argv[]){
	char text[MAXB];
	char *lineptr[MAXLINES];
	int nlines;
	int (*numbers)(void *,void *) =(int (*)(void *,void *))strcmp;
	int i,type;
	type=0;
	for(i=1;argc-i>0;i++){
		if(strcmp(argv[i], "-n")==0)
			type='n';
		else if(strcmp(argv[i], "-f")==0)
			type +='f';
		else if(strcmp(argv[i], "-d")==0)
			type +='d';
	}
	switch(type){
		case 'n' :
			numbers=(int (*)(void *,void *))numcmp;
			break;
		case 'f' :
			numbers=(int (*)(void *,void *))strvcmp;
			break;
		case 'd' :
			numbers=(int (*)(void *,void *))strdcmp;
			break;
		default :
			printf("error args\n");
			break;
	}
	if((nlines=readlines(text, lineptr,MAXLINES))>=0){
        qsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))numbers);	
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


int numcmp(char *s, char *t){
	double n1,n2;
	n1=atof(s);
	n2=atof(t);
	if(n1>n2)
		return 1;
	else if(n1==n2)
		return 0;
	else
		return -1;
}

int strvcmp(char *s, char *t){
	int c;
	int i;
	for(i=0;tolower(s[i])==tolower(t[i]);i++)
		if(s[i]=='\0')
			return 0;
	return tolower(s[i]) - tolower(t[i]);
}

int strdcmp(char *s, char *t){
	int i=0;
	int j=0;
	while(s[i]!='\0' && t[j]!='\0'){
		if(!isalnum(s[i])&&s[i]!=' ')
			i++;
		if(!isalnum(t[i])&&t[i]!=' ')
			j++;
		if(s[i]==t[j])
			i++, j++;
			else if((isalnum(s[i]) || s[i]==' ')&&(isalnum(t[j]) || t[j]==' '))
			return s[i] - t[j];
	}
	return s[i] - t[j];
}
