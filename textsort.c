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
int readlines(char *text,char *lineptr[], int);
void writelines(char *lineptr[] , int);
int getLine(char *, int);
int numcmp(char *, char *);
int strvcmp(char *,char *);
int strdcmp(char *,char *);
int getWord(char *,int, int);
int strnncmp(char *,char *);
static unsigned char match=0;
static int num=0;

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
		case W :
			numbers=(int (*)(void *,void *))strnncmp;
			break;
		default :
			printf("error args\n");
			break;
	}
	if((nlines=readlines(text, lineptr,MAXLINES))>=0){
        qqsort((void **)lineptr,0,nlines-1,(int (*)(void *,void *))(num>0) ? strnncmp : numbers);	
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
	for(curptr=text;(cl=getLine(tmp,MAXLEN))>0;curptr+=cl+1){
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

int strnncmp(char *s,char *t){
	int i,starts,startt;
	int n;
	char ss[100];
	char tt[100];
	extern int num;
	int a=0;
	for(i=0,n=0;s[i]!='\0'&& n<num;){
		while(s[i]==' ' || s[i]=='\t')
			i++;
		a=0;
		if(isalnum(s[i])){
			n++;
			starts=i;
			while(isalnum(ss[a++]=s[i++]))
				; 
		}
	}
	ss[--a]='\0';
	for(i=0,n=0;t[i]!='\0'&& n<num;){
		while(t[i]==' ' || t[i]=='\t')
			i++;
		a=0;
		if(isalnum(t[i])){
			n++;
			startt=i;
			while(isalnum(tt[a++]=t[i++]))
				;
		}
	}
	tt[--a]='\0';
	return strdcmp(ss,tt);
	/*for(;s[starts]==t[startt];starts++,startt++)
		if(!isalnum(s[starts]))
			return 0;
	return s[starts] - t[startt];*/
}
			

