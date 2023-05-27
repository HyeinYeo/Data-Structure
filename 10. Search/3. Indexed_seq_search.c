// 색인순차탐색
#define ISIZE // 인덱스 테이블 크기
#define SIZE // 원래 배열 크기
int list[SIZE];

typedef struct{
	int key;
	int idx;
}itable;
itable ilist[ISIZE]; // 인덱스 테이블

int indexed_seq_search(int key, int n){ // n은 list 크기 
	int i, low, high = n-1;
	// key가 범위 벗어났으면 오류
	if (key < list[0] || key > list[n-1]) return -1;
	
	// 인덱스 테이블의 어떤 키들 사이에 key가 존재하면
	for (i = 0; i < ISIZE-1; i++)
		if (ilist[i].key <= key && key < ilist[i+1].key)
			break;
	
	// low에 하한값의 인덱스, high에 상한값의 인덱스-1 넣어서 이진탐색
	low = ilist[i].idx;
	high = ilist[i+1].idx - 1; // 상한값의 인덱스 전까지만 탐색하도록
	return binary_search(key, low, high); 
} 
