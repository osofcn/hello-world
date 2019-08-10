#include <stdio.h>
#define MAXL 1000
#define SHIFTL 30
#define MOSTL 60

int getLine(char oneline[],int maxl);
void getsub(char oneline[],int cl,char subline[]);
int main(void){
	int c;
	char oneline[MAXL];
	char subline[MAXL];
	while((c=getLine(oneline,MAXL))>0){
		if(c>=MOSTL){
			getsub(oneline,c,subline);
			printf("%s%d",subline,c);
		}
		else{
	        	printf("%s",oneline);
		}
	}
}
int getLine(char oneline[],int maxl){
	int c,i;
	for(i=0;i<maxl-1&&(c=getchar())!=EOF&&c!='\n';i++)
		oneline[i]=c;
	if(c=='\n'){
		oneline[i]=c;
		i++;
	}
	oneline[i]='\0';
	i++;
	return i;
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

				

