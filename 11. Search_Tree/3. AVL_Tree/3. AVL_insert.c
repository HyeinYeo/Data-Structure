// AVL 삽입 함수
/*
	1. 이진탐색트리 삽입과 유사 -> 대신 아래에서부터 재균형해와야 하므로 재귀로 수행
	2. 삽입 후 재균형 함수 수행 
*/ 
typedef struct AvlNode{
	int data;
	struct AvlNode *left, *right;
}AvlNode; 

AvlNode *insert_avl(AvlNode **root, int key){
	// 0. 공백 트리 or 삽입 위치 -> 노드 생성 후 삽입
	if (*root == NULL){
		*root = (AvlNdoe*)malloc(sizeof(AvlNode));
		if (*root == NULL) exit(1);
		(*root)->data = key;
		(*root)->left = (*root)->right = NULL; // 단말노드 삽입 
	}
	
	// 1. 키가 해당 노드 키보다 작을 때 => 왼쪽 서브트리 탐색
	else if (key < (*root)->data){
		(*root)->left = insert_avl(&((*root)->left), key);
		(*root) = rebalance(root);
	}
	
	// 2. 키가 해당 노드 키보다 클 때 => 오른쪽 서브트리 탐색
	else if (key > (*root)->data){
		(*root)->right = insert_avl(&((*root)->right), key);
		(*root) = rebalance(root);
	} 
	
	// 3. 키 탐색 성공 => 삽입 진행하지 않음
	else
		exit(1);
	
	return *root; 
}
