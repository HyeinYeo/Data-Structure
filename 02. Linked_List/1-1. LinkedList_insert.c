/* 단순연결리스트 삽입함수 */
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode;

// phead: 헤드포인터의 포인터(공백리스트인 경우에 삽입하기 위함)
// p : 선행노드 (그 다음이 삽입 위치)
// node : 삽입될 노드 
void insert_node(ListNode **phead, ListNode *p, ListNode *node){
	// 1. 공백 리스트인 경우
	if (!(*phead)){
		node->link = NULL;
		*phead = node;
	}
		
	// 2. 첫 번째 위치에 삽입(헤드 포인터에 연결하는 경우)
	else if (!p){
		node->link = *phead; // 현재 헤드 포인터가 가리키는 노드를 그 다음 노드로 이어줌
		*phead = node; 
	}
	// 3. p 다음 삽입 
	else{
		node->link = p->link;
		p->link = node;
	} 
}
