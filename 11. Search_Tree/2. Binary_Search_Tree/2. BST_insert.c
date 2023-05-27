// 이진탐색트리 삽입 연산
/*
	키 탐색
		- 탐색 실패 => 실패 위치에 노드 삽입
		- 탐색 성공 => 이미 있는 키이므로 종료 
*/ 

typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

void insert_bst(BSTNode **root, int key, int data){ // 빈 트리일 경우 root에 삽입하기 위해 이중포인터로 입력 
	BSTNode *parent = NULL; // 삽입 위치의 부모
	BSTNode *ptr = *root; // 삽입 위치
	BSTNode *node; // 삽입할 때 새로 생성할 노드 가리킬 포인터 
	
	// 1. 삽입위치 실패(null) 만날 때까지 키를 탐색한다
	while (ptr != NULL){
		// 0) 키가 해당 노드의 키와 같을 경우(탐색 성공) -> 이미 있는 키이므로 종료 
		if (ptr->key == key) return; 
		
		// 탐색 실패한 경우
		parent = ptr; // 삽입 위치의 부모노드 저장 
		// 1) 키가 해당 노드의 키보다 작을 경우 -> 왼쪽 서브트리로
		if (key < ptr->key)
			ptr = ptr->left;
		
		// 2) 키가 해당 노드의 키보다 클 경우 -> 오른쪽 서브트리로
		else if (key > ptr->key)
			ptr = ptr->right;
	}
	
	// 2. 삽입위치 찾음
	// 	1) 삽입할 노드 생성
	node = (BSTNode*)malloc(sizeof(BSTNode));
	node->key = key;
	node->data = data;
	node->left = node->right = NULL; // 단말에 삽입되므로 링크는 모두 null 
	
	//  2) 공백트리 아닌 경우엔(부모 존재) 부모노드 키값과 비교하여 적절한 자식 노드 위치에 연결
	if (parent != NULL){
		if (key < parent->key) parent->left = node;
		else parent->right = node;
	}
	
	//  3) 공백트리인 경우엔 루트로 연결(루트 포인터 이용)
	else
		*root = node; 	 
}
