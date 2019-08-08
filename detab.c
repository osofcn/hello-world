#include <stdio.h>
#define TABS 8
#define MAXL 1000

int getLine(char oneline[],int maxl);
void tabtospace(char yline[],int cl,char toline[]);
void spacetotab(char yline[],int cl,char toline[]);

int main(void){
	int cl;
	char yline[MAXL];
	char toline[MAXL];
	while((cl=getLine(yline,MAXL))>0){
			spacetotab(yline,cl,toline);
			printf("%s",toline);
			}
}
int 	getLine(char oneline[],int maxl)	{
	int cl,c;
	for(cl=0;cl<maxl-1&&(c=getchar())!=EOF&&c!='\n';cl++)
		oneline[cl]=c;
	if(c=='\n'){
		oneline[cl]=c;
		cl++;
	}
	oneline[cl]='\0';
	return cl;
}
void tabtospace(char yline[],int cl,char toline[]){
	int i,j,k;
	j=0;
	for(i=0;i<cl;i++){
		if(yline[i]=='\t'){
                        k=TABS-i%TABS+TABS;
			for(int s=1;s<=k;s++){
				toline[j]=' ';
				j++;
			}

		}
		else{
			toline[j]=yline[i];
			j++;
		}
	}
	toline[j]='\0';
}
void spacetotab(char yline[],int cl,char toline[]){
	int i,j,k,g;
	j=0;
	k=0;
	for(i=0;i<cl;i++){
		if(yline[i]==' '&&k<8)
			k++;
		else{
			if(k==8){
				k=0;
				toline[j]='\t';
				j++;
				i--;
			}
			else if(k!=0){
				for(int s=0;s<k;s++){
					toline[j]=' ';
					j++;}
				k=0;
				i--;
			}
			else{
				toline[j]=yline[i];
				j++;
			}
		}
	}
	yline[j]='\0';
}

