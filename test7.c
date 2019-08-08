#include <stdio.h>

int main(void){
	int c;
	int cc[128];
	for(int i=0;i<=127;i++)
		cc[i]=0;
	while((c=getchar())!=EOF)
		if(c>=40)
		cc[c]++;
	for(int j=0;j<127;j++){
		if(cc[j]!=0){
			putchar(j);
			putchar(' ');
			for(int k=0;k<cc[j];k++)
				putchar('#');
			putchar('\n');
		}
	}
}
