// 힙 정렬 2 - heapify
// 힙은 최대힙으로 heapify(오름차순 정렬)
/*
	- 배열의 절반부터(반절은 리프노드이기 때문에)
	- 아래쪽에서부터 heapify
	----------------------------------------------
	- 힙 구성 => O(n)
	- 힙 정렬 => O(nlogn)
	따라서, O(n + nlogn) = O(nlogn) 
*/ 

void adjust(int list[], int root, int n){
	int i = root; // down-heap 때의 i=1과 같음 
	int child = i * 2; // down-heap 때의 child=2와 같음
	 
	int tmp = list[root]; // down-heap 때의 tmp = h->heap[h->hsize](루트로 옮긴 값)과 같음
	
	while (child <= n){
		if (child < n && list[child] < list[child+1])
			child++;
		
		if (tmp < list[child]){
			list[i] = list[child];
			i = child;
			child *= 2;
		}
		else //tmp > list[child]
			break; 
	} 
	list[i] = tmp;
}

void heapSort2(int list[], int n){
	int i, t;
	
	// 1. 배열의 절반부터 루트까지 가면서 heapify
	for (i = n/2; i > 0; i--)
		adjust(list, i, n); // i를 루트로 하는 포리스트 heapify
	
	// 2. 루트값과 배열 마지막 값 교환 => 맨 뒤에서부터 정렬 되게 함
	for (i = n-1; i > 0; i--){ // n-1부터 i값 시작하는 이유는 1개는 정렬되었음을 표시하고 시작하려고 
		SWAP(list[1], list[i+1], t);
		adjust(list, 1, i); // 삭제 후, 힙 재조정. 1개 정렬되었으므로 i(n-1)개를 전체 개수로 넘김 
	} 
}
