// ����Ž��Ʈ�� �ִ�Ű/�ּ�Ű Ž��
typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

// 1. �ִ�Ű Ž�� => ���� �����ʿ� �ִ� Ű
BSTNode *search_bst_max(BSTNode *node){
	// ��Ʈ��尡 null�� �ƴ� Ʈ���� ����, ������ �ڽ��� null�� ������ 
	while ((node != NULL) && (node->right != NULL))
		node = node->right;
	return node;
}

// 2. �ּ�Ű Ž�� => ���� ���ʿ� �ִ� Ű
BSTNode *search_bst_min(BSTNode *node){
	// ��Ʈ��尡 null�� �ƴ� Ʈ���� ����, ���� �ڽ��� null�� ������
	while ((node != NULL) && (node->left != NULL))
		node = node->left;
	return node;
}
