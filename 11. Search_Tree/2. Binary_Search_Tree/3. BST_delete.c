// ����Ž��Ʈ�� ����
/*
	1. �ܸ���� ���� �� �׳� ����
	2. �ڽ� ��� 1�� �ִ� ��� �� �ڽĳ�带 �θ���� ����
	3. �ڽ� ��� 2�� �ִ� ��� �� ������ �ڽĳ���� ���� ���� ��带 �İ��ڷ� ������
*/

typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

void delete_bst(BSTNode **root, int key){
	BSTNode *parent = NULL; // ������ ����� �θ���
	BSTNode *child; // ������ ����� �ڽĳ��(case 2), �İ��� ����� ������ �ڽĳ��(case 3)
	BSTNode *target = *root; // ������ ��� 
	
	// 0. ������� Ž�� -> Ž�� �����ϸ� Ʈ���� ������ ��� ����
	while (target != NULL && target->key != key){
		parent = target;
		if (key < target->key) target = target->left;
		else target = target->right;
	}
	if (target == NULL) return; // Ž�� ������ ��� ����
	
	// 1. �ܸ���� ����
	if (target->left == NULL && target->right == NULL){
		if (parent != NULL){ // ��Ʈ ������ �ƴ� ��� 
			if (parent->left == target) // ���� ��尡 �θ����� ���� �ڽ��̸�
				parent->left = NULL;
			else // ���� ��尡 �θ����� ������ �ڽ��̸�
				parent->right = NULL;
		}
		else // ��Ʈ ������ ��� => ����Ʈ�� ��
			*root = NULL; 
	}
	
	// 2. �ڽ� ��� 1�� �ִ� ���
	else if (target->left == NULL || target->right == NULL){
		if (target->left != NULL) // �ڽ� ��尡 ���� �ڽ��� ���
			child = target->left;
		else // �ڽ� ��尡 ������ �ڽ��� ���
			child = target->right;
		
		// �ڽ� ��带 �θ��忡 ����
		if (parent != NULL){
			if (parent->left == target)
				parent->left = child;
			else
				parent->right = child; 
		}
		else // ��Ʈ ������ ��� => child�� ��Ʈ�� �� 
			*root = child;
	}
	
	// 3. �ڽ� ��� 2�� �ִ� ���
	else{
		// 1) �İ��� ����: ��������� ������ �ڽĳ���� ���� ���� ���
		parent = target; // ���߿� �İ����� ������ ����Ʈ���� ���̱� ���� �İ����� �θ� 
		child = target->right; // ��������� ������ �ڽĳ��
		while (child->left != NULL){ // ���� ���� ���(=�İ���) ã�� ������ 
			parent = child;
			child = child->left;
		}
		
		// 2) �İ����� �ڽ� ��带 �İ����� �θ� ����� �ڽĳ��� ���� 
		if (parent->left == child) // �İ��ڰ� �θ��� ���� �ڽĳ���� ��� 
			parent->left = child->right; // �İ����� ������ ����Ʈ���� ���� ����
		else // �İ��ڰ� �θ��� ������ �ڽĳ���� ���
			parent->right = child->right;
		
		// 3) ���� ��带 �İ��ڷ� ��ü 
		target->key = child->key;
		target = child; 
	}
	free(target); // ���� 
}
 
