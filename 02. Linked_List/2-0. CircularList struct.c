/*원형연결리스트 구조체*/
// 단순연결리스트와 같다. 단, 마지막 노드의 link가 NULL이 아닌 첫 번째 노드를 가리킨다 
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode; 
