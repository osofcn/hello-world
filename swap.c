#include <stdio.h>
#define swap(t,x,y) {  \
	t tp;   \
	tp=x;   \
	x=y;    \
	y=tp;   \
}

int main(void){
	int x=232;
	int y=21;
	float x1=23.53;
	float y1=33.33;

	swap(int,x,y)
	swap(float,x1,y1)
	
	printf("x=%d,y=%d\nx1=%f,y1=%f",x,y,x1,y1);
}
