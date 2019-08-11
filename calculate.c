#include <stdio.h>
#include <math.h>

#define NUMBER 0
#define NUMSIZE 100

int getop(char[]);
double atof(char[]);
double pop(void);
void push(double);
int main(void){
	char s[NUMSIZE];
	int type;
	double op2;
	while((type=getop(s))!=EOF){
	switch(type){
		case 0 :
			push(atof(s));
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
			printf("unknow command %s\n",s);
			break;
		}
	}
	return 0;
}


			

