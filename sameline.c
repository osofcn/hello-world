#include <stdio.h>
#include <string.h>

int main(void){
	FILE *f1,*f2;
	char line1[100], line2[100];
	
	if((f1=fopen("test8.c","r")) == NULL)
		fprintf(stderr,"can't open f1");
	if((f2=fopen("test9.c","r")) ==NULL)
		fprintf(stderr,"can't open f2");
	while(fgets(line1,100,f1)!= NULL && fgets(line2,100,f2)!= NULL)
		if(strcmp(line1,line2)!=0){
			printf("%s",line1);
			return 0;
		}
	fclose(f1);
	fclose(f2);
}
