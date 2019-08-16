/* 用快速排序的方法对字符串指针数组进行排序，
 * 为了简单用递归函数完成。   */


void qsort(void *v[], int left, int right, int (*cmpr)(void *, void *)){
	int i, last;
	void swap(void *v[], int i, int j);
	
	if(left>=right)
		return;
	swap(v,left, (left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if((*cmpr)(v[i],v[left])<0)
				swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1,cmpr);
	qsort(v, last+1,right,cmpr);
}

void swap(void *v[], int i, int j){
	void *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
