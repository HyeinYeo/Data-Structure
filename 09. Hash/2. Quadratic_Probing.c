// ���������
#define M 50 // ��Ŷ�� ���� ���� 1����� ����(1���� �迭)

int HashTable[M];
typedef struct element{
	int data;
	int key;
}element;

// �ؽ����̺� ������ �ִ� �Լ�
void QuadProbingHashing(element e){ // e => data, key�� �̷���� ���� 
	int hb, cb, i = 1;
	
	// 1. ������ �ؽ��Լ� ���
	hb = h(e.key);
	
	// 2. �浹 �߻� �˻� -> �浹 �ذ�: �� ��Ŷ ã��
	for (cb = hb; HashTable[cb] && HashTable[cb].key != e.key;){
		// �浹 �ذ�(���������)
		cb = (cb + i) % M;
		i += 2;
		/*
		cb = (hb + i*i) % M;
		i++;
		*/
		// ��Ŷ �� á���� �˻�
		if (cb == hb) return; 
	} 
	if(!HashTable[cb]) // �� �ؽ����̺��̸�, ������ ����
		HashTable[cb] = e; 
} 
