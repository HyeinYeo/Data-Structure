#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}Node;

// 1) ���� 
int smaller(Node *p, int x){
	if (!p || p->data > x) return 0;
	return 1 + smaller(p->link, x);
}

// 2) ���� 
void rsort(Node *p){
	if (p->link)
		rsort(p->link);
	printf("%d ", p->data);
}

// 3) ���� 
void insert(Node *p, int x){
	Node *ptr = p, *q = NULL, *node;
	node = (Node*)malloc(sizeof(Node));
	node->data = x;
	//node->link = NULL;
	
	while (ptr && ptr->data <= x){
		q = ptr; ptr = ptr->link;
	}
	if (!p){
		node->link = NULL;
		p = node;
	}
	else if (!q){
		node->link = p;
		p = node;
	}
	else{
		q->link = node;
		node->link = ptr;
	}
}

void display(Node *p){
	Node *ptr = p;
	while (ptr){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

int main(){
	Node *node, *p, *ptr;
	int i, x = 6, n = 8;
	int list[8] = {1, 1, 3, 5, 5, 7, 8, 9};
	node = (Node*)malloc(sizeof(Node));
	node->data = list[0];
	node->link = NULL;
	p = node;
	ptr = p;
	node = NULL;
	for(i = 1; i < n; i++){
		node = (Node*)malloc(sizeof(Node));
		node->data = list[i];
		node->link = NULL;
		ptr->link = node;
		ptr = ptr->link;
		node = NULL;
	}
	printf("�ʱ� ����Ʈ: ");
	display(p);
	
	i = smaller(p, x);
	printf("%d���� �۰ų� ���� ������ ��: %d\n", x, i);
	
	printf("�������� ���: ");
	rsort(p);
	printf("\n");
	
	insert(p, 6);
	printf("6 ���� ���� ����Ʈ: ");
	display(p);
	
	insert(p, 5);
	printf("5 ���� ���� ����Ʈ: ");
	display(p);
	 
}
