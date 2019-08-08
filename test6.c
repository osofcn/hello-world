#include <stdio.h>
#define IN 1
#define OUT 0

int main(void){
	int c;
	int state=OUT;
	while((c=getchar())!=EOF){
		if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
			state=IN;
			putchar('#');
		}
		else if(state==IN){
			state=OUT;
			putchar('\n');
		}
	}
}
