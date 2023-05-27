#include <stdio.h>
typedef struct node_t {
	int key;
	struct node_t *link;
} node_t;

/*
node_t *reverse(node_t *head)
{
	node_t *p, *q, *r;
	p = head;
	q = NULL;
	while (p != NULL){
		r = p;
		p = p->link;
		head = p;
		r->link = q;
		q = r;
	}
	return q;
}
*/
node_t *reverse(node_t *head)
{
	node_t *first, *rest;
	if (head == NULL) return NULL;
	first = head;
	rest = first->link;
	if (rest == NULL) return head;
	
	head = reverse(rest);
	rest->link = first;
	first->link = NULL;
	return head; 
}

int main(){
	node_t n5 = {5, NULL};
	node_t n4 = {4, &n5};
	node_t n3 = {3, &n4};
	node_t n2 = {2, &n3};
	node_t n1 = {1, &n2};
	
	node_t *ptr;
	node_t *ptr2;
	printf("reverse Àü: ");
	for (ptr = &n1; ptr != NULL; ptr=ptr->link)
		printf("%d ", ptr->key);
	printf("\nreverse ÈÄ: ");
	ptr = reverse(&n1);
	for (; ptr != NULL; ptr=ptr->link)
		printf("%d ", ptr->key);
}
