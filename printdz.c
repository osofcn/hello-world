#include <stdio.h>
#include <ctype.h>
int main(void){
	int c , n;
	n=0;
	while((c=getchar()) != EOF){
		if(isgraph(c))
			putchar(c);
		else
			printf(" \\%o " , c);
		n++;
		if(n >40){
			putchar('\n');
			n = 0;
		}
	}
	putchar('\n');
}
