/* 比较两个字符串的大小，前者比后者大则输出>0，相等则
 * 输出=0，前者比后者小则输出<0 */

int strcm(char *s, char *t){
	for(;*s == *t;s++,t++)
		if(*s=='\0')
			return 0;
	return *s - *t;
}
