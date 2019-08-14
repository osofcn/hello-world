#include <stdio.h>
#define MAXL 1000
#define SHIFTL 30
#define MOSTL 60

int getLine(char oneline[],int maxl);
void getsub(char oneline[],int cl,char subline[]);
extern int strindex(char [],char[]);

int main(void){
	int c,d;
	char oneline[MAXL];
	char subline[]="sub";
	while((c=getLine(oneline,MAXL))>0){
		if((d=strindex(oneline,subline))>=0)
		printf("%d%s",d,oneline);
	}
	return 0;
}
int getLine(char *oneline,int maxl){
	int c;
	char *ptr;
	ptr=oneline;
	while(--maxl>0&&(c=getchar())!=EOF&&c!='\n')
		*oneline++=c;
	if(c=='\n')
		*oneline++=c;
	*oneline='\0';
	return oneline-ptr;
}

void getsub(char oneline[],int cl,char subline[]){
	int i,j,k,l;
	k=-1;
	j=0;
	l=0;
	for(i=0;i<cl;i++){
		if((l+1)%SHIFTL!=0){
		if(oneline[i]==' '||oneline[i]=='\t'){
			subline[j]=oneline[i];
			j++;
			l++;
			k=i;
		}
		else{
			subline[j]=oneline[i];
			l++;
			j++;
		}
		}
		else{
			l=0;
			if(k==-1){
				subline[j]='\n';
				j++;
			}
			else{
				subline[j-(i-k)]='\n';
				j=j-(i-k)+1;
				i=k;
				k=-1;
			}
		}
	}
	subline[j]='\0';
}

				

