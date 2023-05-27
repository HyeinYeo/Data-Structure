// 힙 구조체
#define MAX_SIZE 100

typedef struct element{
	int val;
}element;

typedef struct HeapType{
	element heap[MAX_SIZE]; // 배열로 구현
	int hsize; // 힙에 있는 노드 크기 
}HeapType; 
