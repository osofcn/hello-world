#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101

int geWord(char *, int);

struct nlist{
	struct nlist *next;
	char *key;
	char *alter;
};

static struct nlist *hasharray[HASHSIZE];

unsigned hashcal(char *key){
	unsigned hashval;
	for(hashval=0; *key!='\0'; key++)
		hashval = hashval*31 + *key;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *key){
	struct nlist *p;
	for(p = hasharray[hashcal(key)]; p != NULL; p = p->next)
		if(strcmp(key , p->key)==0)
			return p;         //found;
	return NULL;      //not found;
}

struct nlist *allocnl(void){
	return (struct nlist *)malloc(sizeof(struct nlist));
}

char *allockey(char *key){
	char *kp;
	kp = (char *)malloc(strlen(key)+1);
	if(kp != NULL)
		strcpy(kp, key);
	return kp;
}

struct nlist *insertkey(char *key ,char *alter){
	struct nlist *p;
	int hashval;
	if((p = lookup(key)) == NULL){  //not found
		if((p = allocnl()) == NULL || (p->key = allockey(key)) == NULL)
			return NULL;

		hashval = hashcal(key);	
		p->next = hasharray[hashval];
		hasharray[hashval] = p;
	}else
		free((void *)p->alter);
	if((p->alter = allockey(alter)) == NULL)
		return NULL;
	return p;
}

void undef(char *key){
	struct nlist *p, *np;
	int hashval;
	if((p = lookup(key)) != NULL){
		hashval=hashcal(key);
		if((np = hasharray[hashval]) == p)
			hasharray[hashval] = NULL;
		else{
			for(; np-> next != p; np = np->next)
				;
			np->next = p->next;
			free((void *)p->key);
			free((void *)p->alter);
			free((void *)p);
		}
	}
}

int main(void){
	char w[101],key[101],alter[101];
	int c;
	struct nlist *p;
	while(getWord(w,100)>0){
		if(w[0] =='#' && strcmp(w,"#define")==0){
			if((c=getWord(w,100))!='\n' &&c != EOF)
				strcpy(key,w);
			else
				ungetch(c);
			while((c=getWord(w,100))!='\n' && c != EOF)
				strcat(alter,w);
			insertkey(key,alter);
		}
		if((p = lookup(w)) != NULL)
			printf("%s ", p->alter);
		else
			printf("%s ", w);
	}
}
