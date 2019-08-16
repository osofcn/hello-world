#include <stdio.h>
#define MAXL 1000
#define TABS 8

int getLine(char oneline[],int maxl);
void spacetotab(char yline[],int cl,char toline[],int tabl);
extern double atof(char *f);

    int main(int argc, char *argv[]){
	int c;
	char oneline[MAXL];
	char toline[MAXL];
	int tabl;
	if(argc==1)
		tabl=TABS;
	else if(argc==2)
		tabl=(int)atof(*++argv);
	else{
		printf("error arg");
		return 1;
	}
	while((c=getLine(oneline,MAXL))>0){
		spacetotab(oneline,c,toline,tabl);
		printf("%s",toline);
	}
	return 0;
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
	return i;
}

void spacetotab(char yline[],int cl,char toline[], int tabl){
	int i,j,k;
	k=0;
	j=0;
	for(i=0;i<cl;i++){
		if(yline[i]==' '){
			k++;
			if((i+1)%tabl==0){
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


					

