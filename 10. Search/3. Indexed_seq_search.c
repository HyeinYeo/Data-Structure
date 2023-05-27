// ���μ���Ž��
#define ISIZE // �ε��� ���̺� ũ��
#define SIZE // ���� �迭 ũ��
int list[SIZE];

typedef struct{
	int key;
	int idx;
}itable;
itable ilist[ISIZE]; // �ε��� ���̺�

int indexed_seq_search(int key, int n){ // n�� list ũ�� 
	int i, low, high = n-1;
	// key�� ���� ������� ����
	if (key < list[0] || key > list[n-1]) return -1;
	
	// �ε��� ���̺��� � Ű�� ���̿� key�� �����ϸ�
	for (i = 0; i < ISIZE-1; i++)
		if (ilist[i].key <= key && key < ilist[i+1].key)
			break;
	
	// low�� ���Ѱ��� �ε���, high�� ���Ѱ��� �ε���-1 �־ ����Ž��
	low = ilist[i].idx;
	high = ilist[i+1].idx - 1; // ���Ѱ��� �ε��� �������� Ž���ϵ���
	return binary_search(key, low, high); 
} 
