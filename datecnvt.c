#include <stdio.h>

        int *daytab[2];
 
int day_of_year(int year,int month, int day)
{
	int i,leap,dayy;
	dayy=day;
	leap= year%4==0&&year%100!=0 ||year%400 ==0;
	if(year<=0 || month>12 || month <1)
		return -1;
	for(i=1;i<month; i++){
		if(dayy>daytab[leap][i] || dayy<1)
			return -1;
		day += *(daytab[leap]+i);
	}
	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday){
	int i, leap;
	leap= year%4==0 && year%100!=0 || year%400==0;
	if(year<=0 || yearday<0 || yearday>365+leap)
		return -1;
	for(i=1;yearday>daytab[leap][i];i++)
		yearday -=daytab[leap][i];
	*pmonth=i;
	*pday=yearday;
	return 0;
}

int main(void){
	int month,day;
	int s[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int s2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	daytab[1]=s2;
	daytab[0]=s;
	month_day(2016,45,&month,&day);
	printf("%d月%d日,   %d\n",month,day,day_of_year(2019,4,6));
}
       
