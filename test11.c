#include <stdio.h>
#include <limits.h>

int pintl(void);
int pintmin(void);

int main(void){
	printf("unsigned char的取值范围为：[0,%d]\n",UCHAR_MAX);
	printf("unsigned int的取值范围为：[0,%u]\n",UINT_MAX);
	printf("unsigned short的取值范围为：[0,%d]\n",USHRT_MAX);
	printf("unsigned long的取值范围为：[0,%lu]\n",ULONG_MAX);
	printf("signed char的取值范围为：[%d,%d]\n",SCHAR_MIN,SCHAR_MAX);
	printf("signed int的取值范围为：[%d,%d]\n",pintmin(),pintl());
	printf("signed short的取值范围为：[%d,%d]\n",SHRT_MIN,SHRT_MAX);
	printf("signed long的取值范围为：[%d,%ld]\n",LONG_MIN,LONG_MAX);

}

int pintl(void){
	int i=1;
	while(i+1>0){
		i++;
	}
	return i;
}

int pintmin(void){
	int i=-1;
	while(i-1<0){
		i--;
	}
	return i;
}
