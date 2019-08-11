#include <stdio.h>

unsigned setbits(unsigned,int,int,unsigned);
unsigned invert(unsigned,int,int);
unsigned rightrot(unsigned,int);

int main(void){
	int x;
	int y;
	scanf("%x",&x);
	printf("%x\n",rightrot(x,4));

}

unsigned setbits(unsigned x,int p,int n,unsigned y){
	return ((y & ~(~0 << n)) <<(p-n)) | (x & (~((~(~0 << n)) <<(p-n))));
}

unsigned invert(unsigned x,int p,int n){
	return (~x & ((~(~0 << n)) <<(p-n))) | (x & ~(~(~0 << n) <<(p-n)));
}

unsigned rightrot(unsigned x,int n){
	return ((x & ~(~0 << n)) << (sizeof x)*8-n) | (x >> n);
}



