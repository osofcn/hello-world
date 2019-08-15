#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define NUMBER 0
#define NUMSIZE 100

int getop(char[]);
double atof(char[]);
double pop(void);
void push(double);

int main(int argc,char *argv[]){
	char s[NUMSIZE];
	int sv;
	int type;
	double op2;
	double var[26];
	while((type=getop(s))!=EOF){
	switch(type){
		case 0 :
			push(atof(s));
			break;
		case '=' :
			if(isupper(sv)){
				pop();
				var[sv-'A']=pop();
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
			if(isupper(type))
				push(var[type-'A']);
			else
			printf("unknow command %s\n",s);
			break;
		}
	sv=type;
	
	}


	return 0;
}


			

