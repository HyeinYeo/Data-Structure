// 힙 삭제 
/*
	- 루트는 제거하고, 배열의 맨 마지막 노드를 루트에 옮겼다고 생각한 뒤
	  자식 노드 중 큰/작은 것과 비교하여 크/작으면 down-heap  
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
element delete_maxheap(HeapType *h){
	int i, child; // child: 큰 자식노드 인덱스 저장할 변수
	element item; // 삭제할 루트노드 저장할 변수
	element tmp; // 배열 맨 마지막 노드 저장할 변수
	
	item = h->heap[1];
	tmp = h->heap[h->hsize];
	h->hsize--;
	
	i = 1; child = 2;
	while (child <= h->hsize){
		if (child < h->hsize && h->heap[child].val < h->heap[child+1].val) // 오른쪽 자식노드가 왼쪽 자식노드보다 크면
			child++; // 오른쪽 자식노드와 비교
		
		if (tmp.val < h->heap[child].val){ // 자식노드가 더 크면 -> down-heap 
			h->heap[i] = h->heap[child];
			i = child; // down-heap
			child *= 2; // child = 2 * i 
		}
		else
			break;
	}
	h->heap[i] = tmp;
	return item; // 삭제값 반환 
} 

// 최소힙
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
