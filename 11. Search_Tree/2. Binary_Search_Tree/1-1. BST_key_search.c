// 이진탐색트리 탐색연산
typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

// 1. 순환으로 구현 
BSTNode *search_key_bst(BSTNode *node, int key){
	// root가 null이면 null 반환(무효 트리, 종료조건)
	if (!node) return NULL;
	
	// 키를 찾았으면 해당 노드 반환
	if (node->key == key) return node;
	
	// null도 아니고, 찾는 키도 아니면
	// 1) 찾으려는 키가 해당 노드 키보다 작으면 -> 왼쪽 서브트리
	else if (key < node->key)
		return search_key_bst(node->left, key);
		
	// 2) 찾으려는 키가 해당 노드 키보다 크면 -> 오른쪽 서브트리
	else // key > node->key
		return search_key_bst(node->right, key);
} 

// 2. 반복으로 구현
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
