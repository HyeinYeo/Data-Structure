// 이진탐색
// - 정렬된 배열에 사용 O(log n)

#define MAX 50
int list[MAX];

// 1. 순환
int binary_search1(int key, int low, int high){
	int mid; // 반으로 가를 변수
	if (low <= high){
		mid = (low + high) / 2;
		if (list[mid] == key) return mid;
		else if (list[mid] > key)
			return binary_search1(key, low, mid-1);
		else
			return binary_search1(key, mid+1, high);
	} 
	return -1; // 탐색 실패 
}

// 2. 반복
int binary_search2(int key, int low, int high){
	int mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (list[mid] == key) return mid;
		else if (list[mid] > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
