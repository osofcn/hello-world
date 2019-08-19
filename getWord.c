/* 读取每一行，得到每一行中指定的字段。 */
#include <stdio.h>
#include <ctype.h>

int getWord(char *word, int lim){
	int c, getch(void);
	void ungetch(int);
	char *w =word;

	while(isspace(c = getch()))
		;
	if (c!=EOF)
		*w++ =c;
	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for(; --lim >0; w++)
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w= '\0';
	return word[0];
}
