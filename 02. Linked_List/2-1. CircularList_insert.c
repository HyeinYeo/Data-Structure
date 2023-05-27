/*원형연결리스트 삽입함수*/
/*
	- head 포인터는 항상 마지막 노드를 가리키고 있음(tail 포인터 같은 느낌)
	- head->link가 가장 첫 번째 노드 

*/
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode; 

// ptail : tail 포인터의 포인터
// node : 삽입 노드 가리키는 포인터 

// 1. 맨 처음에 삽입하는 경우
ListNode *insert_first(ListNode **ptail, ListNode *node){
	// 1-1. 빈 리스트인 경우
	if (!(*ptail)){
		*ptail = node;
		node->link = node;
	} 
	
	// 1-2. 빈 리스트가 아닌 경우
	else{
		node->link = (*ptail)->link;
		(*ptail)->link = node;
	}
	return *ptail;
}

// 2. 끝에 삽입하는 경우
ListNode *insert_last(ListNode **ptail, ListNode *node){
	// 2-1. 빈 리스트인 경우
	if (!(*ptail)){
		*ptail = node;
		node->link = node;
	}
	// 2-2. 빈 리스트가 아닌 경우
	else{
		node->link = (*ptail)->link;
		(*ptail)->link = node;
		*ptail = node; // tail 포인터를 새로 삽입한 노드 포인팅하는 걸로 바꿔줌 
	}
	return *ptail; // 바뀐 포인터 리턴 
}
