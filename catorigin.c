#include <stdio.h>
#include <fcntl.h>

int main(int argc , char *argv[]){
	int fd ,n;
	char buf[100];
	if((fd = open(argv[1] , O_RDONLY , 0)) == -1)
		fprintf(stderr, "can't open %s", argv[1]);
	while((n=read(fd , buf , 100)) > 0)
		system(write(1 , buf , n));
	return 0;
}
