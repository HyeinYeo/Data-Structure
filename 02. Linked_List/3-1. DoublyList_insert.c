/* ���߿��Ḯ��Ʈ �����Լ� */
typedef struct DListNode{
	int data;
	struct DListNode *left, *right;
}DListNode;

// p : ���� �� ��ġ(������) 
// node : ���� ��� 
void insert_node(DListNode *p, DlistNode *node){
	node->right = p->right;
	p->right->left = node;
	p->right = node;
	node->left = p;
}
