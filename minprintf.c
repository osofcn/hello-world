#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p,sval[100];
	int i = 0;
	double dval;

	va_start(ap,fmt);
	for(p = fmt;*p != '\0';p++){
		if(*p == '%'){
			sval[i++] = '%';
			while(isdigit(*++p))
				sval[i++] = *p;
			if(*p == '.'){
				sval[i++] = '.';
				while(isdigit(*++p))
					sval[i++] = *p;
			}
				sval[i] = '\0';
			switch(*p){
				case 'd' :
				case 'i' :
					sval[i++] = 'd';
					sval[i] ='\0';
					printf(sval , va_arg(ap , int));
					break;
				case 'f' :
					sval[i++] = 'f';
					sval[i] ='\0';
					printf(sval , va_arg(ap , double));
					break;
				case 's' :
					sval[i++] = 's';
					sval[i] ='\0';

					printf(sval , va_arg(ap , char *));
					break;
				case 'c' :
					sval[i++] = 'c';
					sval[i] = '\0';
					printf(sval , va_arg(ap , int));
					break;
				default :
					putchar(*p);
					break;
				}
		}else
			putchar(*p);
		i = 0;
	}
	va_end(ap);
}

int main(void){
	minprintf("test : %10.5s %d !\n", "helloword !" , 2345);
	return 0;
}
