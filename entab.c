#include <stdio.h>
#define MAXL 1000
#define TABS 8

int getLine(char oneline[],int maxl);
void spacetotab(char yline[],int cl,char toline[]);
int main(void){
	int c;
	char oneline[MAXL];
	char toline[MAXL];
	while((c=getLine(oneline,MAXL))>0){
		spacetotab(oneline,c,toline);
		printf("%s",toline);
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

void spacetotab(char yline[],int cl,char toline[]){
	int i,j,k;
	k=0;
	j=0;
	for(i=0;i<cl;i++){
		if(yline[i]==' '){
			k++;
			if((i+1)%TABS==0){
				toline[j]='\t';
				j++;
				k=0;
				
			}
		}
		else if(k!=0){
			for(int s=0;s<k;s++){
				toline[j]=' ';
				j++;
			}
			k=0;
			i--;
		}
		else{
			toline[j]=yline[i];
			j++;
		}
	}
	toline[j]='\0';
}


					

