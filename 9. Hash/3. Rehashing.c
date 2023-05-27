// ���ؽ�

#define M 50 // ��Ŷ�� ���� ���� 1����� ����(1���� �迭)

int HashTable[M];
typedef struct element{
	int data;
	int key;
}element;

// �ؽ����̺� ������ �ִ� �Լ�
void Rehashing(element e){
	int hb, cb, rb, i;
	hb = h(e.key); // ���ؽ��Լ�(h)�� ����� ������ �ؽð�
	rb = rh(e.key); // ���ؽ��Լ�(rh)�� ����� ��(�浹 �� ������ ��)
	i = rb;
	
	for (cb = hb; HashTable[cb] && HashTable[cb].key != e.key; ){
		cb = (cb + i) % M; // rb += 1;
		if (cb == hb) return;
	}
	if (!HashTable[cb])
		HashTable[cb] = e;
} 
