// ������ ����Ʈ�� ������ȸ
typedef struct TNode{
	int data;
	struct TNode *left, *right;
	short left_thread, right_thread; // True��� ������/�ļ��� ����Ű�� ���� 
}TNode;
TNode *find_successor(TNode *node); // ���� �ļ��� ã�� �Լ� 

void thread_inorder(TNode *root){
	TNode *ptr = root;
	
	// 1. ������ȸ ���������� �̵�(Ʈ���� ���� ���� �������)
	while (ptr->left)
		ptr = ptr->left;
	
	// 2. ���� ������, ���� �ļ��ڷ� �ٷ� �̵�
	do{
		printf("%d", ptr->data);
		ptr = find_successor(ptr); // �ļ��� ã�ƿ� 
	} while(ptr); // ������ �ڽ�(�ļ���) null �Ǳ� ������ 
} 
