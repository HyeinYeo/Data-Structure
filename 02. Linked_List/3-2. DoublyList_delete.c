/* ���߿��Ḯ��Ʈ ���� �Լ� */
typedef struct DListNode{
	int data;
	struct DListNode *left, *right;
}DListNode;

// head : ��� ������ 
// node : ���� ��� 
void delete_node(DListNode *head, DlistNode *node){
	if (head == node) return;
	
	node->right->left = node->left;
	node->left->right = node->right;
	free(node);
}
