#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
void undcl(void);
void ungetss(char *);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int error=0;
int isf=0;

int main(void){
	while(gettoken()!=EOF){
		if(tokentype!=NAME){
			printf("missing tpye\n");
			return 1;
		}else if(!strcmp(token,"const")){
			strcpy(datatype,"const ");
			gettoken();
		}
		
		strcat(datatype,token);
		out[0]='\0';
		dcl();
		if(tokentype!='\n'){
			while(gettoken()!='\n');
			error=1;
			printf("too much express%s\n",token);
		}
		if(error)
			error=0;
		
			printf("%s: %s%s\n",name, out, datatype);
	}
	return 0;
}

int gettoken(void){
	int getch(void);
	void ungetch(int);
	int c;
	char *p=token;
	while((c=getch())==' ' || c=='\t')
		;
	if(c=='('){
		if((c=getch())==')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		}
		else{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if(c=='['){
		 *p++='[';
		while((c=getch())!=']'&&c!=EOF&&c!='\n')
			*p++=c;
		if(c=='\n' ||c==EOF){
			printf("error dcl\n");
			error=1;
		}
		else{
		*p++=']';
		*p='\0';
		return tokentype = BRACKETS;
		}
	}
	else if(isalpha(c)){
		*p++=c;
		while(isalnum(c=getch()))
			*p++=c;
		ungetch(c);
		*p='\0';
		return tokentype = NAME;
	}
	else{
		token[0]=c;
		token[1]='\0';
		return tokentype = c;
	}
}

void dcl(void){
	int ns=0;
	while(gettoken() == '*')
		ns++;
/*	if(tokentype==NAME && !strcmp(token,"char")){
		isf=1;
		printf("test%s",token);
		return;
	}*/
	dirdcl();
	while(ns-- >0)
		strcat(out,"pointer to ");
}

void dirdcl(void){
	if(tokentype=='('){
		dcl();
	/*	if(isf==1){
			isf=0;
			while(gettoken()!=')');
			strcat(out, "funtion returning");
		}*/
		if(tokentype!= ')'){
			printf("error tcl\n");
			error=1;
		}
	}
	else if(tokentype==NAME)
		strcpy(name, token);
	else{
		printf("error dcl\n");
		error=1;
	}
	while(gettoken()==PARENS || tokentype==BRACKETS || tokentype=='('){
		if(tokentype==PARENS)
			strcat(out, "function returning ");
		else if(tokentype=='('){
			        strcat(out,"含有参数");
				while(gettoken()!=')')
					strcat(out, token);
				strcat(out, "的函数 returning ");
		}
		else{
			strcat(out, "array ");
			strcat(out, token);
			strcat(out," of ");
		}
	}
}

void undcl(void){
	char tmp[MAXTOKEN];

	while(gettoken()!=EOF){
		if(tokentype==NAME)
			strcpy(out, token);
		else
			printf("error synax\n");
		while(gettoken()!='\n'){
			if(tokentype==PARENS)
				strcat(out, token);
			else if(tokentype==BRACKETS)
				strcat(out, token);
			else if(tokentype=='*'){
				if(gettoken()==PARENS || tokentype==BRACKETS)
					sprintf(tmp, "(* %s)",out);
				else
					sprintf(tmp,"* %s",out);
				ungetss(token);
				tokentype='*';
				strcpy(out,tmp);
			}
			else if(tokentype==NAME){
				sprintf(tmp, "%s %s",token,out);
				strcpy(out,tmp);
			}
			else
				printf("error synax\n");
		}
		printf("%s\n",out);
	}
}
