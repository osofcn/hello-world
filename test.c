#include <stdio.h>

int main(void){
	char a[]="sfs";
	char *p=a;
        *(p+1)='d';	
	printf("%s",p);
}
