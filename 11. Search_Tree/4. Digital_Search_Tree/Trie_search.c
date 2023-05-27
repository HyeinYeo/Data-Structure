// �ٿ� Ʈ���� Ž��
#define MAX 27 // ���ĺ� ���� + ���Ṯ�� ���� 
typedef struct trieNode{
	int tag; // 1�̸� ������ ���, 0�̸� ����(�б�)��� 
	struct trieNode *child[MAX]; 
	char *key;
}trieNode; 

trieNode *trie_search(trieNode *node, char *key, int level){ // level: Ʈ���� ����
	if (!node) return NULL; // ���� Ʈ����
	
	// ������(�ܸ�) ��忡 ������ ��� -> Ű ��
	if (node->tag == 1){
		if (node->key == key) // Ž�� ����
			return node;
		else
			return NULL; // Ž�� ���� 
	} 
	
	// ���� �б����� ���
	/*
		- node->child[getIndex(key, level)]
			- �ش� ���ĺ��� ���� ���� �̵�
			- getIndex(key, level): ���� ���������� Ű(level��° ���ĺ�)�� �ε���
		- level + 1
			- ���� ������ �̵�(���� ���� ���ĺ�) 
	*/
	// 
	return trie_search(node->child[getIndex(key, level)], key, level+1); 
}
