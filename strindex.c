#include <string.h>

int strindex(char s[],char t[]){
	int i,j,k;
	for(i=strlen(s)-1;i>=0;i--){
		for(j=i,k=strlen(t)-1;j>=0&&k>=0&&s[j]==t[k];j--,k--);
		if(k<0)
			return i-strlen(t)+2;
	}
	return -1;
}

