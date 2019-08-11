#include <ctype.h>
#include <stdio.h>
#include <math.h>


double atof(char s[]){
	double val,power;
	int va;
	int i,sign,signe;

	for(i=0;isspace(s[i]);i++);
	sign=(s[i]=='-')? -1 : 1;
	if (s[i]=='+'|| s[i]=='-')
		i++;
	for (val=0.0; isdigit(s[i]); i++)
		val=10.0*val+(s[i]-'0');
	if(s[i]=='.')
		i++;
	for(power =1.0; isdigit(s[i]);i++){
		val=10.0 * val + (s[i]-'0');
		power *=10;
	}
	if(s[i]=='e'|| s[i]=='E'){
		i++;
		signe=(s[i]=='-')? -1 : 1;
		if(s[i]=='+' || s[i]=='-')
			i++;
		for(va=0; isdigit(s[i]); i++)
			va=10*va+(s[i]-'0');
		va=signe*va;
	
		power /=pow(10,va);
	}
	return sign * val / power;
}
