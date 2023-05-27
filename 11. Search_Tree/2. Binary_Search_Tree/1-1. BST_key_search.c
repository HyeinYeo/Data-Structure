// ����Ž��Ʈ�� Ž������
typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

// 1. ��ȯ���� ���� 
BSTNode *search_key_bst(BSTNode *node, int key){
	// root�� null�̸� null ��ȯ(��ȿ Ʈ��, ��������)
	if (!node) return NULL;
	
	// Ű�� ã������ �ش� ��� ��ȯ
	if (node->key == key) return node;
	
	// null�� �ƴϰ�, ã�� Ű�� �ƴϸ�
	// 1) ã������ Ű�� �ش� ��� Ű���� ������ -> ���� ����Ʈ��
	else if (key < node->key)
		return search_key_bst(node->left, key);
		
	// 2) ã������ Ű�� �ش� ��� Ű���� ũ�� -> ������ ����Ʈ��
	else // key > node->key
		return search_key_bst(node->right, key);
} 

// 2. �ݺ����� ����
BSTNode *search_key_bst(BSTNode *node, int key){
	while (node != NULL){
		if (node->key == key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
} 
