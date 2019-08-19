//定义了一个结构作为树的节点；
//
//
struct tnode {
	char *word;
	int count;
	struct tnode *same;
	struct tnode *left;
	struct tnode *right;
};
