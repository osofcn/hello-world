#include <stdio.h>

int htoi(char hstr[]);

int main(void){
	int h;
          char s[]="0x2fb5";
	  h=htoi(s);
	  printf("%d %x\n",h,h);
}

int htoi(char hstr[]){
	int i,h;
	i=0;
	h=0;
	if(hstr[i]=='0'&&(hstr[i+1]=='x'||hstr[i+1]=='X'))
		i=2;
	while((hstr[i]>='0'&&hstr[i]<='9')||(hstr[i]>='a'&&hstr[i]<='f')||(hstr[i]>='A'&&hstr[i]<='F')){
		if(hstr[i]>='0'&&hstr[i]<='9')
			h=h*16+(hstr[i]-'0');
		else if(hstr[i]>='a'&&hstr[i]<='f')
			h=h*16+10+(hstr[i]-'a');
		else
			h=h*16+10+(hstr[i]-'A');
		i++;
	}
	return h;
}

