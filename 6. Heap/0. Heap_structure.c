// �� ����ü
#define MAX_SIZE 100

typedef struct element{
	int val;
}element;

typedef struct HeapType{
	element heap[MAX_SIZE]; // �迭�� ����
	int hsize; // ���� �ִ� ��� ũ�� 
}HeapType; 
