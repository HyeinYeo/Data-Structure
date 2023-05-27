// 이진탐색트리 최대키/최소키 탐색
typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

// 1. 최대키 탐색 => 가장 오른쪽에 있는 키
BSTNode *search_bst_max(BSTNode *node){
	// 루트노드가 null이 아닌 트리에 대해, 오른쪽 자식이 null일 때까지 
	while ((node != NULL) && (node->right != NULL))
		node = node->right;
	return node;
}

// 2. 최소키 탐색 => 가장 왼쪽에 있는 키
BSTNode *search_bst_min(BSTNode *node){
	// 루트노드가 null이 아닌 트리에 대해, 왼쪽 자식이 null일 때까지
	while ((node != NULL) && (node->left != NULL))
		node = node->left;
	return node;
}
