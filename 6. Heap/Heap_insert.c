// �� ����
/*
	- �迭 �� �������� �ְ�, �θ���� ���ؼ� ��Ʈ ���� ������ shift-up 
*/
#define MAX_SIZE 100

typedef struct element{
	int val;
}element;

typedef struct HeapType{
	element heap[MAX_SIZE]; // �迭�� ����
	int hsize; // ���� �ִ� ��� ũ�� 
}HeapType; 

// �ִ��� 
void insert_maxheap(HeapType *h, element item){
	int i; // �迭 �� ������ ��ġ ���� ����
	h->hsize++; // item �����ϹǷ� �� ������ 1 ������Ŵ
	i = h->hsize;
	
	while (i > 0){ // ��Ʈ���� 
		if (h->heap[i/2].val < item.val){ // �θ��庸�� ũ��
			h->heap[i] = h->heap[i/2]; // �θ���� �ٲ� 
			i /= 2; // shift-up 
		}
		else break;
	}
	h->heap[i] = item;
} 

// �ּ���
void insert_minheap(HeapType *h, element item){
	int i;
	h->hsize++;
	i = h->hsize;
	
	while (i > 0) {
		if (item.val < h->heap[i/2].val){ // �θ��庸�� ������ 
			h->heap[i] = h->heap[i/2];
			i /= 2;
		}
		else break;
	}
	h->heap[i] = item;
}
