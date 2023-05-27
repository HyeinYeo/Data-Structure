// 힙 삽입
/*
	- 배열 맨 마지막에 넣고, 부모노드랑 비교해서 루트 만날 때까지 shift-up 
*/
#define MAX_SIZE 100

typedef struct element{
	int val;
}element;

typedef struct HeapType{
	element heap[MAX_SIZE]; // 배열로 구현
	int hsize; // 힙에 있는 노드 크기 
}HeapType; 

// 최대힙 
void insert_maxheap(HeapType *h, element item){
	int i; // 배열 맨 마지막 위치 넣을 변수
	h->hsize++; // item 삽입하므로 힙 사이즈 1 증가시킴
	i = h->hsize;
	
	while (i > 0){ // 루트까지 
		if (h->heap[i/2].val < item.val){ // 부모노드보다 크면
			h->heap[i] = h->heap[i/2]; // 부모노드랑 바꿈 
			i /= 2; // shift-up 
		}
		else break;
	}
	h->heap[i] = item;
} 

// 최소힙
void insert_minheap(HeapType *h, element item){
	int i;
	h->hsize++;
	i = h->hsize;
	
	while (i > 0) {
		if (item.val < h->heap[i/2].val){ // 부모노드보다 작으면 
			h->heap[i] = h->heap[i/2];
			i /= 2;
		}
		else break;
	}
	h->heap[i] = item;
}
