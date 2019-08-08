#include <stdio.h>
#define Y 1
#define N 0

int                main(void){
	int c;
	int         d=N;
	while((c=getchar())!=EOF){
		if(c==' '){
			if(d==N){
				d=Y;
				putchar(c);
			}
		}
		else{
			d=N;
			putchar(c);
		}
	}
}
