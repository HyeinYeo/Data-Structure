/* �ܼ����Ḯ��Ʈ �����Լ� */
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode;

// phead: ����������� ������(���鸮��Ʈ�� ��쿡 �����ϱ� ����)
// p : ������ (�� ������ ���� ��ġ)
// node : ���Ե� ��� 
void insert_node(ListNode **phead, ListNode *p, ListNode *node){
	// 1. ���� ����Ʈ�� ���
	if (!(*phead)){
		node->link = NULL;
		*phead = node;
	}
		
	// 2. ù ��° ��ġ�� ����(��� �����Ϳ� �����ϴ� ���)
	else if (!p){
		node->link = *phead; // ���� ��� �����Ͱ� ����Ű�� ��带 �� ���� ���� �̾���
		*phead = node; 
	}
	// 3. p ���� ���� 
	else{
		node->link = p->link;
		p->link = node;
	} 
}
