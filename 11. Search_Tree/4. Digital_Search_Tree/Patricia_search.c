// ��Ʈ���� Ž�� 
typedef struct PatriciaNode{
	int bitNumber;
	int data;
	PatriciaNode *left, *right;
}PatriciaNode;

PatriciaNode *patricia_search(PatriciaNode *header, unsigned int k){
	PatriciaNode *next, *curr;
	if (!header) return NULL; // �� Ʈ��
	
	next = header->left;
	curr = header;
	
	// ���� bitNumber�� ���� bitNumber���� �۰ų� �������� Ž�� ���� 
	while (next->bitNumber > curr->bitNumber){
		curr = next;
		if (bit(k, next->bitNumber)) // k�� ���� bitNumber ��ġ�� �ش��ϴ� ��Ʈ�� 1�̸�
			next = next->right; // ������ �ڽ����� �̵�
		else
			next = next->left; 
	} 
	return next;	
}
