// ����Ž��Ʈ�� ���� ����
/*
	Ű Ž��
		- Ž�� ���� => ���� ��ġ�� ��� ����
		- Ž�� ���� => �̹� �ִ� Ű�̹Ƿ� ���� 
*/ 

typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

void insert_bst(BSTNode **root, int key, int data){ // �� Ʈ���� ��� root�� �����ϱ� ���� ���������ͷ� �Է� 
	BSTNode *parent = NULL; // ���� ��ġ�� �θ�
	BSTNode *ptr = *root; // ���� ��ġ
	BSTNode *node; // ������ �� ���� ������ ��� ����ų ������ 
	
	// 1. ������ġ ����(null) ���� ������ Ű�� Ž���Ѵ�
	while (ptr != NULL){
		// 0) Ű�� �ش� ����� Ű�� ���� ���(Ž�� ����) -> �̹� �ִ� Ű�̹Ƿ� ���� 
		if (ptr->key == key) return; 
		
		// Ž�� ������ ���
		parent = ptr; // ���� ��ġ�� �θ��� ���� 
		// 1) Ű�� �ش� ����� Ű���� ���� ��� -> ���� ����Ʈ����
		if (key < ptr->key)
			ptr = ptr->left;
		
		// 2) Ű�� �ش� ����� Ű���� Ŭ ��� -> ������ ����Ʈ����
		else if (key > ptr->key)
			ptr = ptr->right;
	}
	
	// 2. ������ġ ã��
	// 	1) ������ ��� ����
	node = (BSTNode*)malloc(sizeof(BSTNode));
	node->key = key;
	node->data = data;
	node->left = node->right = NULL; // �ܸ��� ���ԵǹǷ� ��ũ�� ��� null 
	
	//  2) ����Ʈ�� �ƴ� ��쿣(�θ� ����) �θ��� Ű���� ���Ͽ� ������ �ڽ� ��� ��ġ�� ����
	if (parent != NULL){
		if (key < parent->key) parent->left = node;
		else parent->right = node;
	}
	
	//  3) ����Ʈ���� ��쿣 ��Ʈ�� ����(��Ʈ ������ �̿�)
	else
		*root = node; 	 
}
