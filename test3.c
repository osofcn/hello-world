#include <stdio.h>
int main(void){
	long entercount=0;
	long tcount=0;
	long scount=0;

	int c;
        while((c=getchar())!=EOF){
        if(c=='\n')
		entercount++;
	else if(c=='\t')
		tcount++;
	else if(c==' ')
		scount++;
        }
	printf("一共有%ld行,制表符有%ld个，空格有%ld个\n",entercount,tcount,scount);
}
