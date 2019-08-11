/* 一个简单的栈push和pop功能 */
#include <stdio.h>
#define SMAX 100

double opstack[SMAX];
int p=0;

void push( double op){
	if(p<SMAX)
		opstack[p++]=op;
}

double pop(void){
	if(p>0)
		return opstack[--p];
	else{
		printf("栈中没有元素");
		return  0.0;
	}
}

void printop(void){
	if(p>0)
	printf("%f",opstack[p-1]);
}

double copytop(void){
	if(p>0)
	return opstack[p-1];
	else{
		printf("栈中没有元素");
		return 0.0;
	}
}

int shifttop(void){
	double d;
	if(p>1){
	d=opstack[p-1];
	opstack[p-1]=opstack[p-2];
	opstack[p-2]=d;
	return 1;
	}
	return 0;
}

void emptystack(void){
	p=0;
}


