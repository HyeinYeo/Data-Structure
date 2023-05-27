/*�������Ḯ��Ʈ �����Լ�*/
/*
	- head �����ʹ� �׻� ������ ��带 ����Ű�� ����(tail ������ ���� ����)
	- head->link�� ���� ù ��° ��� 

*/
typedef struct ListNode{
	int data;
	struct ListNode *link;
}ListNode; 

// ptail : tail �������� ������
// node : ���� ��� ����Ű�� ������ 

// 1. �� ó���� �����ϴ� ���
ListNode *insert_first(ListNode **ptail, ListNode *node){
	// 1-1. �� ����Ʈ�� ���
	if (!(*ptail)){
		*ptail = node;
		node->link = node;
	} 
	
	// 1-2. �� ����Ʈ�� �ƴ� ���
	else{
		node->link = (*ptail)->link;
		(*ptail)->link = node;
	}
	return *ptail;
}

// 2. ���� �����ϴ� ���
ListNode *insert_last(ListNode **ptail, ListNode *node){
	// 2-1. �� ����Ʈ�� ���
	if (!(*ptail)){
		*ptail = node;
		node->link = node;
	}
	// 2-2. �� ����Ʈ�� �ƴ� ���
	else{
		node->link = (*ptail)->link;
		(*ptail)->link = node;
		*ptail = node; // tail �����͸� ���� ������ ��� �������ϴ� �ɷ� �ٲ��� 
	}
	return *ptail; // �ٲ� ������ ���� 
}
