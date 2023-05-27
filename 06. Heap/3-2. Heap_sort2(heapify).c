// �� ���� 2 - heapify
// ���� �ִ������� heapify(�������� ����)
/*
	- �迭�� ���ݺ���(������ ��������̱� ������)
	- �Ʒ��ʿ������� heapify
	----------------------------------------------
	- �� ���� => O(n)
	- �� ���� => O(nlogn)
	����, O(n + nlogn) = O(nlogn) 
*/ 

void adjust(int list[], int root, int n){
	int i = root; // down-heap ���� i=1�� ���� 
	int child = i * 2; // down-heap ���� child=2�� ����
	 
	int tmp = list[root]; // down-heap ���� tmp = h->heap[h->hsize](��Ʈ�� �ű� ��)�� ����
	
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
	
	// 1. �迭�� ���ݺ��� ��Ʈ���� ���鼭 heapify
	for (i = n/2; i > 0; i--)
		adjust(list, i, n); // i�� ��Ʈ�� �ϴ� ������Ʈ heapify
	
	// 2. ��Ʈ���� �迭 ������ �� ��ȯ => �� �ڿ������� ���� �ǰ� ��
	for (i = n-1; i > 0; i--){ // n-1���� i�� �����ϴ� ������ 1���� ���ĵǾ����� ǥ���ϰ� �����Ϸ��� 
		SWAP(list[1], list[i+1], t);
		adjust(list, 1, i); // ���� ��, �� ������. 1�� ���ĵǾ����Ƿ� i(n-1)���� ��ü ������ �ѱ� 
	} 
}
