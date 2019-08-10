#include <stdio.h>
#include <string.h>

int any(char[],char[]);

int main(void){
	char s1[]="sfsadfsadfsadfsadfsafdasdfsddfgghfhhjjioiopoertuoefvdnvld";
	char s2[]="uvwad";
	printf("%s\n%s\n%d\n",s1,s2,any(s1,s2));
}

int any(char s1[],char s2[]){
	int i=0;
	int j=0;
	for(i=0;i<strlen(s1);i++){
		for(j=0;j<strlen(s2);j++){
			if(s1[i]==s2[j])
				return i+1;
		}
	}
		return -1;
}


