#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MAXLINES 5000
#define MAXB 10000
#define D 0x0fU
#define F 0xf0U
#define N 0x04U
#define W 0x02U

extern void qqsort(void *v[], int ,int,int (*)(void *, void *));
int readlines(char *text,char *lineptr[], int,int (*)(void *,int,int));
void writelines(char *lineptr[] , int);
int getLine(char *, int);
int numcmp(char *, char *);
int strvcmp(char *,char *);
int strdcmp(char *,char *);
int getWord(char *,int, int);

static unsigned char match=0;
static int num=1;

int main(int argc, char *argv[]){
	char text[MAXB];
	char *lineptr[MAXLINES];
	int nlines;
	int (*numbers)(void *,void *) =(int (*)(void *,void *))strdcmp;
	int i;
	for(i=1;argc-i>0;i++){
		if(strcmp(argv[i], "-n")==0)
			match |=N;
		else if(strcmp(argv[i], "-f")==0)
			match |=F;
		else if(strcmp(argv[i], "-d")==0)
			match |=D;
		else if(argv[i][1]=='w'){
			match |=W;
			num=(argv[i]+2==0) ? 1 : atoi(argv[i]+2);
		}

	}
	switch(match){
		case 0 :
			break;
		case N :
			numbers=(int (*)(void *,void *))numcmp;
			break;
		case F :
			numbers=(int (*)(void *,void *))strdcmp;
			break;
		case D :
			numbers=(int (*)(void *,void *))strdcmp;
			break;
		default :
			printf("error args\n");
			break;
	}
	if((nlines=readlines(text, lineptr,MAXLINES,(int (*)(void *,int,int))(match== W) ? getWord : getLine))>=0){
        qqsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))numbers);	
	writelines(lineptr, nlines);
	return 0;
	}
	else{
		printf("error: input too big to sort\n");
		return 1;
	}
}

int readlines(char *text, char *lineptr[], int maxlines,int (*getwl)(void *,int,int)){
	int cl,nlines;
	char tmp[MAXLEN], * curptr;

	nlines=0;
	for(curptr=text;(cl=(*getwl)(tmp,MAXLEN,num))>0;curptr+=cl+1){
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
	char cps,cpt;
	unsigned char d,f;
	d=f=0;
	d=match & D;
	f=match & F;
	do{
		if(d){
		while(!isalnum(s[i])&&s[i]!=' '&&s[i]!='\0')
			i++;
		while(!isalnum(t[j])&&t[j]!=' '&&t[j]!='\0')
			j++;
		}
		cps=(f) ? tolower(s[i]) :s[i];
		i++;
		cpt=(f) ? tolower(t[j]) :t[j];
		j++;
		if(cps=='\0' &&cpt=='\0')
			return 0;
	}while(cps == cpt);
	return cps - cpt;
}
