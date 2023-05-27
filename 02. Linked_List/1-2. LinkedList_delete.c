/* 단순연결리스트 삭제 함수 */
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode;
// phead: 헤드포인터의 포인터(공백리스트인 경우에 삽입하기 위함)
// p : 선행노드 (그 다음이 삭제노드)
// node : 삭제될 노드 
void delete_node(ListNode **phead, ListNode *p, ListNode *node){
	// 1. 삭제노드가 첫 번째 노드일 경우
	if (*phead == node){
		*phead = node->link;
	}
	// 2.  p 다음 노드 삭제할 경우 
	else{
		p->link = node->link;
	} 
	free(node);
} 

int main(){
	ListNode *n1, *n2, *n3, *head, *ptr;
	n1 = (ListNode*)malloc(sizeof(ListNode));
	n1->data = 2;
	n2 = (ListNode*)malloc(sizeof(ListNode));
	n2->data = 3;
	n3 = (ListNode*)malloc(sizeof(ListNode));
	n3->data = 4;
	n3->link = NULL;
	
	n1->link = n2;
	n2->link = n3;
	head = n1;
	
	ptr = head;
	while (ptr){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
	
	delete_node(&head, head, n1);
	
	ptr = head;
	while (ptr){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	
}
