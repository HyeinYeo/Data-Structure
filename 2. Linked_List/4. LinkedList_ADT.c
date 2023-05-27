/*연결리스트 연산*/
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode;
// 연결리스트 구조체
typedef struct LinkedList{
	ListNode *head;
	int length;
}LinkedList;

int is_empty(LinkedList *list){
	if (!(list->head)) return 1;
	else 0;
}

int get_length(LinkedList *list){
	// return list->length;
	ListNode *ptr = list->head;
	int cnt = 0;
	
	while (ptr){
		cnt++;
		ptr = ptr->link;
	}
	return cnt;
}

ListNode *get_nodeptr(LinkedList *list, int pos){
	ListNode *ptr = list->head;
	int i;
	
	if (pos < 0) return NULL;
	for (i = 0; i < pos; i++)
		ptr = ptr->link;
		
	return ptr;
} 























