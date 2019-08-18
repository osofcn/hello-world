#include <stdio.h>
float wenduc(float f);
int main(void){
	float fwendu;             
	printf("\t华氏温度与摄氏度");            
	for(fwendu=300;fwendu>=0;fwendu-=20){
		printf("%3.0f\t%6.1f\n",fwendu,wenduc(fwendu));
	}
        return 0;
}
float wenduc(float f){
	return 5*(f-32)/9;
}
