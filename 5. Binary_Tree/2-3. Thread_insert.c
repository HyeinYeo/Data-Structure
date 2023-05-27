// 스레드 이진트리 노드 삽입
#define TRUE 1
#define FALSE 0
typedef struct TNode{
	int data;
	struct TNode *left, *right;
	short right_thread; // 편의상 오른쪽 스레드 구분 필드만 넣음 
};

// 오른쪽에 삽입 
void thread_insert_right(TNode *parent, int data){
	TNode *node = (TNode*)malloc(sizeof(TNode));
	node->data = data;
	
	// 1) 새 노드에 부모의 후속자와 right_thread 상태를 옮겨옴
	node->right = parent->right;
	node->right_thread = parent->right_thread;
	
	// 2) 부모노드와 새 노드 잇기
	parent->right = node;
	
	// 3) 부모노드의 right_thread 상태 변화시키기
	parent->right_thread = FALSE; 
	
	// 4) 새 노드의 왼쪽 링크는 null로 초기화
	node->left = NULL; 
}

// 왼쪽에 삽입
void thread_insert_left(TNode *parent, int data){
	TNode *ptr;
	TNode *node = (TNode*)malloc(sizeof(TNode));
	node->data = data;
	
	// 1. 단말노드 위치에 삽입하는 경우
	if (!(parent->left)){
		parent->left = node;
		node->right = parent;
		node->right_thread = TRUE;
	}
	// 2. 중간 위치에 삽입하는 경우 
	else{
		// 1) 부모노드의 왼쪽 자식노드 => 가장 오른쪽 노드의 후속자를 새 노드로 지정
		ptr = parent->left;
		while (!(ptr->right_thread))
			ptr = ptr->right;
		ptr->right = node;
		
		// 2) 부모노드의 왼쪽 자식노드와 새 노드 연결
		node->left = parent->left;
		
		// 3) 부모노드와 연결
		parent->left = node;
		
		// 4) 새 노드의 후속자를 부모노드로 지정
		node->right = parent;
		node->right_thread = TRUE; 
	}		
} 
