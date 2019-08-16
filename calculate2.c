#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define NUMBER 0
#define NUMSIZE 100

int getop(char[]);
double atof(char[]);
double pop(void);
void push(double);
int cal(char []);
int getLine(char oneline[],int maxl);

int main(int argc, char *argv[]){
	char s[NUMSIZE];
	while(argc-- >1)
		cal(*++argv);
	if(argc==1)
		printf("%f\n",pop());
	else
		printf("error\n");

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

int cal(char s[]){
	char sa[NUMSIZE];
	int sv;
	int type;
	double op2;
	double var[26];
	int i;
	int j;
	for(i=0;s[i]!='\0';){
		while(s[i]==' ' || s[i]=='\t')
			i++;
		if(!isdigit(s[i])&&s[i]!='.'&&s[i]!='+'&&s[i]!='-'){
			switch(s[i]){
			case '=' :
				if(isupper(s[i-1])){
					pop();
					var[s[i-1]-'A']=pop();
				}	
				else
					printf("error");
				break;
			case '+' :
				push(pop()+pop());
				break;
			case '-' :
				op2=pop();
				push(pop()-op2);
				break;
			case '*' :
				push(pop()*pop());
				break;
			case '/' :
				op2=pop();
				if(op2==0)
					printf("分母不能为零");
				else
					push(pop()/op2);
				break;
			case '%' :
				op2=pop();
				if((int)op2==0)
					printf("error");
				else
					push((int)pop()%(int)op2);
				break;
			case 's' :
				push(sin(pop()));
				break;
			case 'e' :
				push(exp(pop()));
				break;
			case '^' :
				op2=pop();
				push(pow(pop(),op2));
				break;
			case '\n' :
				printf("\t%f\n", pop());		
				break;
			default :
				if(isupper(s[i]))
					push(var[s[i]-'A']);
				else
					printf("unknow command %s\n",s);
				break;
			}
			i++;
		}
		else{
		       	if((s[i]=='+' || s[i]=='-')&&!isdigit(s[i+1])){
				if(s[i]=='+')
					push(pop()+pop());
				else{
					op2=pop();
					push(pop()-op2);
				}
				i++;
			}
			else{
				j=0;
				if(s[i]=='+' || s[i]=='-')
					sa[j++]=s[i++];
				while(isdigit(s[i]))
					sa[j++]=s[i++];
				if(s[i]=='.'){
					sa[j++]=s[i++];
					while(isdigit(s[i]))
						sa[j++]=s[i++];
				}
				sa[j]='\0';
				push(atof(sa));
			}
		}
	}

}


			

