// AVL Ʈ�� - ����ȭ �Լ�

// 1. �����μ� ���ϱ� => ��ͱ���(Ʈ�� ���� ���ϱ�� ����) 
//    - �����μ�: ���� ����Ʈ�� ���� - ������ ����Ʈ�� ����
//                �ܸ������ ��쿣 ���� ��� null�̱� ������ �����μ� 0 
int getBF(AvlNode *root){
	if (root == NULL) return 0;
	return getBF(root->left) - getBF(root->right);
}

// 2. ����ȭ �Լ�
/*
	1) root �����μ� +2 : ���� ����Ʈ���� ������ ����
		(i) root->left �����μ� 1 : ���� ����Ʈ���� ������ ����
			=> LL ȸ��
		(ii) root->left �����μ� -1 : ������ ����Ʈ���� ������ ����
			=> LR ȸ��
	
	2) root �����μ� -2 : ������ ����Ʈ���� ������ ����
		(i) root->right �����μ� -1 : ������ ����Ʈ���� ������ ����
			=> RR ȸ��
		(ii) root->right �����μ� 1 : ���� ����Ʈ���� ������ ����
			=> RL ȸ��
*/ 

AvlNode *rebalance(AvlNode **root){ // ��Ʈ �ٲ�Ƿ� ���� �����ͷ� ���� 
	int bf = getBF(*root); // bf: root�� �����Լ� -> +2 / -2�� ���� ����
	
	// 1)
	if (bf > 1){
		if (getBF((*root)->left) > 0) // 1)-(i) 
			*root = LL(*root);
		
		else						 // 1)-(ii)
			*root = LR(*root);
	}
	
	// 2)
	if (bf < -1){
		if (getBF((*root)->right) < 0) // 2)-(i)
			*root = RR(*root);
		
		else 						   // 2)-(ii)
			*root = RL(*root);
	}
	return *root;
}
