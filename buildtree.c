
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tnode.h"
//用于把单词加入到二叉树中；

int getWord(char *,int);
int arg=6;

struct tnode *alloctn(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *allocwd(char *s){
	char *p;
	p=(char *) malloc(strlen(s)+1);
	if (p!=NULL)
		strcpy(p, s);
	return p;
}

void insertw(struct tnode *p, char *word){
	struct tnode *tmp;
	tmp = p->same;
	p->same = alloctn();
	p->same->word= allocwd(word);
	p->same->same= tmp;

}

struct tnode *addtree(struct tnode *p,char *word){
	int cond;
	if(p == NULL){
		p = alloctn();
		p->word =allocwd(word);
		p->count++;
		p->same = NULL;
		p->left = NULL;
		p->right = NULL;
	}else if((cond=strncmp(word, p->word,arg))==0)
		insertw( p, word);
	else if(cond>0)
		p->right=addtree(p->right, word);
	else
		p->left=addtree(p->left, word);
	return p;
}

void writeword(struct tnode *p){
	struct tnode *tp;
	if(p!=NULL){
		writeword(p->left);
		tp=p;
		while(tp!=NULL){
			printf("%s ",tp->word);
			tp = tp->same;
		}
		writeword(p->right);
	}
}

int main(int argc, char *argv[]){
	struct tnode *p=NULL;
	char word[100];
	if(argc ==2)
		arg = *argv[1];
	while(getWord(word, 100)!=EOF)
		if(isalpha(word[0]))
			p = addtree( p, word);
	writeword(p);
	return 0;
}




