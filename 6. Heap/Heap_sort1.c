// 힙 정렬 1 - insert/delete
// 최소힙 가정(오름차순 정렬) 
#define MAX_SIZE 100
typedef struct HeapType{
	int heap[MAX_SIZE]; // 배열로 구현
	int hsize; // 힙에 있는 노드 크기 
}HeapType;

void insert_minheap(HeapType *h, int item);
element delete_minheap(HeapType* h);

void heapSort1(int list[], int n){
	int i;
	HeapType h;
	init(&h);
	
	for (i = 0; i < n; i++) 
		insert_minheap(&h, list[i]); // 1개씩 삽입 
		
	for (i = 0; i < n; i++)
		list[i] = delete_minheap(&h); // 1개씩 삭제 
}

void insert_minheap(HeapType *h, int item){
	int i;
	h->hsize++;
	i = h->hsize;
	
	while (i > 0){
		if (h->heap[i].val < h->heap[i/2].val){
			h->heap[i] = h->heap[i/2];
			i /= 2;
		}
		else break;
	}
	h->heap[i] = item;
}

element delete_minheap(HeapType* h){
	int i, child;
	int item, tmp;
	
	item = h->heap[1];
	tmp = h->heap[h->hsize];
	h->hsize--;
	
	i = 1; child = 2;
	while (child <= h->hsize){
		if (child < h->hsize && h->heap[child].val > h->heap[child+1].val)
			child++;
			
		if (h->heap[i].val > h->heap[child].val){
			h->heap[i] = h->heap[child];
			i = child;
			child *= 2;
		}
		else break;
	}
	h->heap[i] = tmp;
	return item;
}
