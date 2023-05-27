/* �ܼ����Ḯ��Ʈ ���� �Լ� */
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode;
// phead: ����������� ������(���鸮��Ʈ�� ��쿡 �����ϱ� ����)
// p : ������ (�� ������ �������)
// node : ������ ��� 
void delete_node(ListNode **phead, ListNode *p, ListNode *node){
	// 1. ������尡 ù ��° ����� ���
	if (*phead == node){
		*phead = node->link;
	}
	// 2.  p ���� ��� ������ ��� 
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
