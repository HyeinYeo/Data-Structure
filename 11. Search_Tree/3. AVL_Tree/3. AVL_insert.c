// AVL ���� �Լ�
/*
	1. ����Ž��Ʈ�� ���԰� ���� -> ��� �Ʒ��������� ������ؿ;� �ϹǷ� ��ͷ� ����
	2. ���� �� ����� �Լ� ���� 
*/ 
typedef struct AvlNode{
	int data;
	struct AvlNode *left, *right;
}AvlNode; 

AvlNode *insert_avl(AvlNode **root, int key){
	// 0. ���� Ʈ�� or ���� ��ġ -> ��� ���� �� ����
	if (*root == NULL){
		*root = (AvlNdoe*)malloc(sizeof(AvlNode));
		if (*root == NULL) exit(1);
		(*root)->data = key;
		(*root)->left = (*root)->right = NULL; // �ܸ���� ���� 
	}
	
	// 1. Ű�� �ش� ��� Ű���� ���� �� => ���� ����Ʈ�� Ž��
	else if (key < (*root)->data){
		(*root)->left = insert_avl(&((*root)->left), key);
		(*root) = rebalance(root);
	}
	
	// 2. Ű�� �ش� ��� Ű���� Ŭ �� => ������ ����Ʈ�� Ž��
	else if (key > (*root)->data){
		(*root)->right = insert_avl(&((*root)->right), key);
		(*root) = rebalance(root);
	} 
	
	// 3. Ű Ž�� ���� => ���� �������� ����
	else
		exit(1);
	
	return *root; 
}
