// ü�ι�

#define M 10
typedef struct element{
	int data;
	int key;
}element;
typedef struct ListNode{
	element item;
	struct ListNode *link;
}ListNode;

// �ؽ� ���̺� ��� ������ �迭
ListNode *htp[M];

void chain(element e, ListNode* hpt[]){
	int hb;
	ListNode *ptr; // �� ��� ������ �� �� ������
	ListNode *lnode; // �� ��� ������ �� �̿��� ���� ��� ����ų ������
	ListNode *node; // ���� ��ġ ã�� �� ����� ������
	 
	// 1. Ű������ �ؽð� ����
	hb = h(e.key);

	// 2. ���� �� ã��(�浹 �� ü�� ������ �� �� ��ġ ã��)
	for(node = hpt[hb]; node; lnode=node, node=node->link){ //lnode���� ������� ����, node�� null���� ������ �� 
		// ü�� ���󰡴ٰ� �̹� �ִ� Ű�� ������ ���� ����
		if (node->item.key == e.key)
			return;
	}
	
	// 3. �� ��� ����
	ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->item = e;
	ptr->link = NULL;
	
	// 4. �� ��� �����ϱ�
	if (lnode != NULL)
		lnode->link = ptr;
		
	else // ���� �ƹ��͵� ü�̴� �� �� ���¿����� 
		htp[hb] = ptr; // �ؽ����̺� ������ �� ó�� ���� 
}
