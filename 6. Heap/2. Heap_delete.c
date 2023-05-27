// �� ���� 
/*
	- ��Ʈ�� �����ϰ�, �迭�� �� ������ ��带 ��Ʈ�� �Ű�ٰ� ������ ��
	  �ڽ� ��� �� ū/���� �Ͱ� ���Ͽ� ũ/������ down-heap  
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
element delete_maxheap(HeapType *h){
	int i, child; // child: ū �ڽĳ�� �ε��� ������ ����
	element item; // ������ ��Ʈ��� ������ ����
	element tmp; // �迭 �� ������ ��� ������ ����
	
	item = h->heap[1];
	tmp = h->heap[h->hsize];
	h->hsize--;
	
	i = 1; child = 2;
	while (child <= h->hsize){
		if (child < h->hsize && h->heap[child].val < h->heap[child+1].val) // ������ �ڽĳ�尡 ���� �ڽĳ�庸�� ũ��
			child++; // ������ �ڽĳ��� ��
		
		if (tmp.val < h->heap[child].val){ // �ڽĳ�尡 �� ũ�� -> down-heap 
			h->heap[i] = h->heap[child];
			i = child; // down-heap
			child *= 2; // child = 2 * i 
		}
		else
			break;
	}
	h->heap[i] = tmp;
	return item; // ������ ��ȯ 
} 

// �ּ���
element delete_minheap(HeapType *h){
	int i, child;
	element item, tmp;
	
	item = h->heap[1];
	tmp = h->heap[h->hsize];
	h->hsize--;
	
	i = 1; child = 2;
	while (child <= h->hsize){
		if (child < h->hsize && h->heap[child].val > h->heap[child+1].val)
			child++;
		
		if (tmp.val > h->heap[child].val){
			h->heap[i] = h->heap[child];
			i = child;
			child *= 2;
		}
		else
			break;
	}
	h->heap[i] = tmp;
	return item;
} 
