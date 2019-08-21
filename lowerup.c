#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
	int c;
	while((c=getchar())!=EOF)
		if(strstr(argv[0],"tolower"))
			putchar(tolower(c));
		else if(strstr(argv[0],"toupper"))
			putchar(toupper(c));
		else
			putchar(c);
}
