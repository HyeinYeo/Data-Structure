/* 이중연결리스트 삭제 함수 */
typedef struct DListNode{
	int data;
	struct DListNode *left, *right;
}DListNode;

// head : 헤드 포인터 
// node : 삽입 노드 
void delete_node(DListNode *head, DlistNode *node){
	if (head == node) return;
	
	node->right->left = node->left;
	node->left->right = node->right;
	free(node);
}
