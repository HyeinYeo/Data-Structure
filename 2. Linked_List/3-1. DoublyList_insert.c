/* 이중연결리스트 삽입함수 */
typedef struct DListNode{
	int data;
	struct DListNode *left, *right;
}DListNode;

// p : 삽입 전 위치(선행노드) 
// node : 삽입 노드 
void insert_node(DListNode *p, DlistNode *node){
	node->right = p->right;
	p->right->left = node;
	p->right = node;
	node->left = p;
}
