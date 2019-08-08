#include <stdio.h>
#define MAXL 1000
#define INNOTE 1
#define OUTNOTE 0

/*这是一个测试删除注释的小程序
                       在第二行的注释*/
int getLine(char oneline[],int maxl);
int delnote(int state,char yline[],int cl,char xline[]);  

int k=-1;
int main(void){
	char yline[MAXL];
	char xline[MAXL];
	int cl;
	int state=OUTNOTE;
	while((cl=getLine(yline,MAXL))>0){
		state=delnote(state,yline,cl,xline);
		printf("%s",xline);
		printf("test" /* be deleted*/);
}
}
                 
int getLine(char oneline[],int maxl){
	int c;
	int i;
	for(i=0;i<maxl-1&&(c=getchar())!=EOF&&c!='\n';i++)
		oneline[i]=c;
	if(c=='\n'){
		oneline[i]='\n';
		i++;}
	oneline[i]='\0';
	return i;
}
                        
int delnote(int state,char yline[],int cl,char xline[]){
	extern int k;
	int i,j;
	j=0;
	for(i=0;i<cl;i++){
		if(state==INNOTE){
			if(yline[i]=='/'&&yline[i-1]=='*')
				state=OUTNOTE;
		}
		else{
			if(yline[i]=='\"'&&yline[i-1]!='\\'){
				k=k*(-1);              /*k表示进入还是走出字符串*/
				xline[j]=yline[i];
				j++;
			}
			else if(yline[i]=='/'&&yline[i+1]=='*'&&k==-1){
				state=INNOTE;
			}
			else{
				xline[j]=yline[i];
				j++;
			}
		}
	}
	xline[j]='\0';
	return state;
}


