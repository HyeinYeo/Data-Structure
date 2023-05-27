// AVL 트리 - 균형화 함수

// 1. 균형인수 구하기 => 재귀구현(트리 높이 구하기와 유사) 
//    - 균형인수: 왼쪽 서브트리 높이 - 오른쪽 서브트리 높이
//                단말노드의 경우엔 양쪽 모두 null이기 때문에 균형인수 0 
int getBF(AvlNode *root){
	if (root == NULL) return 0;
	return getBF(root->left) - getBF(root->right);
}

// 2. 균형화 함수
/*
	1) root 균형인수 +2 : 왼쪽 서브트리가 과중한 상태
		(i) root->left 균형인수 1 : 왼쪽 서브트리가 과중한 상태
			=> LL 회전
		(ii) root->left 균형인수 -1 : 오른쪽 서브트리가 과중한 상태
			=> LR 회전
	
	2) root 균형인수 -2 : 오른쪽 서브트리가 과중한 상태
		(i) root->right 균형인수 -1 : 오른쪽 서브트리가 과중한 상태
			=> RR 회전
		(ii) root->right 균형인수 1 : 왼쪽 서브트리가 과중한 상태
			=> RL 회전
*/ 

AvlNode *rebalance(AvlNode **root){ // 루트 바뀌므로 이중 포인터로 전달 
	int bf = getBF(*root); // bf: root의 균형함수 -> +2 / -2에 따라 나뉨
	
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
