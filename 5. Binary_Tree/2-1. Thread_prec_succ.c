// ������ ����Ʈ�� ������ / �ļ��� ã��
typedef struct TNode{
	int data;
	struct TNode *left, *right;
	short left_thread, right_thread; // True��� ������/�ļ��� ����Ű�� ���� 
}TNode;

// 1. ���� ������ ã��: ���� �ڽ� ����Ʈ���� ���� ������ ��� 
TNode *find_predecessor(TNode *node){
	TNode *prec = node->left;
	
	if (node->left_thread)
		return prec;
	
	while (!(prec->right_thread))
		prec = prec->right;
	return prec; 
}

// 2. ���� �ļ��� ã��: ������ �ڽ� ����Ʈ���� ���� ���� ��� 
//    - ������ȸ ��, �� ��� ������ �� ��尡 ��������? 
TNode *find_successor(TNode *node){
	// 1) ������ �ڽ� ����
	TNode *succ = node->right;
	
	// 2) ������ �ڽ��� ������ ��ũ��� 
	//    => ������ ��ũ�� ����Ű�� ��尡 ���� �ļ��� ���
	if (node->right_thread)
		return succ;
	
	// 3) ������ �ڽ��� ������ ��ũ �ƴ϶��
	//    => ������ �ڽ��� ���� ���� ���� ��� ã�� ������ ��������
	//    => ���� ���� �������� ���� ��ũ�� ������ ��ũ! 
	while (!(succ->left_thread))
		succ = succ->left;
	return succ;
}

