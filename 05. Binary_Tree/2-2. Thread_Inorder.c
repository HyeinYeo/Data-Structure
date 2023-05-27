// 스레드 이진트리 중위순회
typedef struct TNode{
	int data;
	struct TNode *left, *right;
	short left_thread, right_thread; // True라면 선행자/후속자 가리키고 있음 
}TNode;
TNode *find_successor(TNode *node); // 중위 후속자 찾는 함수 

void thread_inorder(TNode *root){
	TNode *ptr = root;
	
	// 1. 중위순회 시작점으로 이동(트리의 가장 왼쪽 리프노드)
	while (ptr->left)
		ptr = ptr->left;
	
	// 2. 다음 순서로, 중위 후속자로 바로 이동
	do{
		printf("%d", ptr->data);
		ptr = find_successor(ptr); // 후속자 찾아옴 
	} while(ptr); // 오른쪽 자식(후속자) null 되기 전까지 
} 
