// ���������
#define M 50 // ��Ŷ�� ���� ���� 1����� ����(1���� �迭)

int HashTable[M];

int LinearProbingSearch(int key){
	int hash_idx; // key�� ���� �ʱ� �ؽ����̺� �ε���(�ʱ� �ؽ��Լ���)
	int real_idx; // �浹�ذ��� ���� ���� �ؽ����̺� �ε���
	
	hash_idx = h(key);
	// �ش� �ε����� ��Ŷ ã�ư�����, �̹� �ٸ� Ű �� ���� �����Ͱ� �����ϸ� for�� ��� ���� 
	for (real_idx = hash_idx; HashTable[real_idx] && HashTable[real_idx].key != key;){
		real_idx = (real_idx + 1) % M; // ���������� ������Ŵ 1->2->3->...
		
		if (real_idx == hash_idx) // ���� ���� �ٽ� ���� ����, ��Ŷ�� �̹� �� �� �� ����(��� �� ã��) 
			return -1; 
	}
	if (HashTable[real_idx].key == key) // Ž�� ���� 
		return real_idx;
	
	return -1; // Ž�� ���� 
} 
