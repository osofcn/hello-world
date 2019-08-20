/* 读取每一行，得到每一行中指定的字段。 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*  得到一个单词的程序。 */
extern int getch();
extern void ungetch(int);

int getWord(char *aword, int maxw){
	int c,getch(void);
	void ungetch(int);
	char *w=aword;

	while((c=getch())==' ' || c=='\t')
		;
	if(c!= EOF)
		*w++ = c;
	if(!isalpha(c) && c!='_' && c!='#' &&c!='\"' &&c!='\\' &&c!='/'){
		*w = '\0';
		return c;
	}

	if(c=='\\'){
		*--w=getch();
		*++w='\0';
	}
	if(c=='/'){
		if((c = getch())!='*'){
			ungetch(c);
			*w='\0';
			return '/';
		}
		else{
			for(; --maxw >0; w++)
				if((c=*w= getch())=='*'){
					if((c=*++w= getch())=='/'){
						w++;
					        break;}
				}
			*w='\0';
			return '/';
		}
	}
						

	if(c=='\"'){
		for(; --maxw >0; w++)
			if((*w= getch())=='\"')
				break;
		return aword[0];
	}

	for(;--maxw >0; w++)
		if( !isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return aword[0];
}

int main(void){
	char aword[100];
	while(getWord(aword,100)>0)
		printf("%s\t" ,aword);
	return 0;
}

		
