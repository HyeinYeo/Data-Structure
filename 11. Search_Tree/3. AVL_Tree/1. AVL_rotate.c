// AVL 탐색트리 - 회전
typedef struct AvlNode{
	int data;
	struct AvlNode *left, *right;
}AvlNode; 

// LL 회전 => 시계방향 
AvlNode *LL(AvlNode *root){
	AvlNode *ptr; // 회전 후 새롭게 루트가 될 노드 가리키는 포인터 
	ptr = root->left;
	root->left = ptr->right;
	ptr->right = root; 
	return ptr;
} 

// RR 회전 => 반시계 방향
AvlNode *RR(AvlNode *root){
	AvlNode *ptr = root->right;
	root->right = ptr->left;
	ptr->left = root;
	return ptr;
} 

// LR 회전 => RR->LL
AvlNode *LR(AvlNode *root){
	AvlNode *x, *y; // x: root 왼쪽 자식, y: x의 오른쪽 자식(새롭게 루트 될 예정) 
	x = root->left;
	y = x->right;
	
	// RR(반시계 회전)
	x->right = y->left;
	y->left = x;
	
	// LL(시계 회전)
	root->left = y->right;
	y->right = root;
	
	return y; 
}

// RL 회전 => LL->RR
AvlNode *RL(AvlNode *root){
	AvlNode *x, *y; // x: root 오른쪽 자식, y: x의 왼쪽 자식(새롭게 루트 될 예정) 
	x = root->right;
	y = x->left;
	
	// LL(시계 회전)
	x->left = y->right;
	y->right = x;
	
	// RR(반시계 회전)
	root->right = y->left;
	y->left = root;
	
	return y;
}
