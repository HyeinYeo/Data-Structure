// AVL Ž��Ʈ�� - ȸ��
typedef struct AvlNode{
	int data;
	struct AvlNode *left, *right;
}AvlNode; 

// LL ȸ�� => �ð���� 
AvlNode *LL(AvlNode *root){
	AvlNode *ptr; // ȸ�� �� ���Ӱ� ��Ʈ�� �� ��� ����Ű�� ������ 
	ptr = root->left;
	root->left = ptr->right;
	ptr->right = root; 
	return ptr;
} 

// RR ȸ�� => �ݽð� ����
AvlNode *RR(AvlNode *root){
	AvlNode *ptr = root->right;
	root->right = ptr->left;
	ptr->left = root;
	return ptr;
} 

// LR ȸ�� => RR->LL
AvlNode *LR(AvlNode *root){
	AvlNode *x, *y; // x: root ���� �ڽ�, y: x�� ������ �ڽ�(���Ӱ� ��Ʈ �� ����) 
	x = root->left;
	y = x->right;
	
	// RR(�ݽð� ȸ��)
	x->right = y->left;
	y->left = x;
	
	// LL(�ð� ȸ��)
	root->left = y->right;
	y->right = root;
	
	return y; 
}

// RL ȸ�� => LL->RR
AvlNode *RL(AvlNode *root){
	AvlNode *x, *y; // x: root ������ �ڽ�, y: x�� ���� �ڽ�(���Ӱ� ��Ʈ �� ����) 
	x = root->right;
	y = x->left;
	
	// LL(�ð� ȸ��)
	x->left = y->right;
	y->right = x;
	
	// RR(�ݽð� ȸ��)
	root->right = y->left;
	y->left = root;
	
	return y;
}
