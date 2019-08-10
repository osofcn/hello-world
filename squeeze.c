#include <stdio.h>
#include <string.h>
void squeeze(char[],char[],char[]);
int main(void){
	char sum[100];
	char sub[100];
	char result[100];
	printf("请输入主字符串:");
	scanf("%s",sum);
	printf("请输入子字符串:");
	scanf("%s",sub);
	squeeze(sum,sub,result);
	printf("结果是：%s\n",result);
}

void squeeze(char sum[],char sub[],char result[]){
	int i,j,k;
	k=0;
	for(i=0;i<strlen(sum);i++){
		for(j=0;j<strlen(sub)&&sum[i]!=sub[j];j++);
		if(j>=strlen(sub)){
			result[k]=sum[i];
			k++;
		}
	}
	result[k]='\0';
}


			
		 


