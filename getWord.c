/* 读取每一行，得到每一行中指定的字段。 */
#include <stdio.h>

extern int getch();
extern void ungetch(int);

int getWord(char *aword, int maxw, int nnum){
	int cl,c,c2,clt;
	cl=0;
	while((c=getch())!='\n' && c!=EOF){
		if(c!=' '&& c!='\t'){
			aword[cl++]=c;
			if((c2=getch())==' ' || c2=='\t'){
				nnum--;
				clt=cl;
				cl=0;
			}
			ungetch(c2);
			if(nnum==0){
				aword[clt]='\n';
				aword[clt+1]='\0';
			}
		}
	
	}
	return clt+1;

}
