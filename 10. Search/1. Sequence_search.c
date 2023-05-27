// 순차탐색 O(n)

#define MAX 50
int list[MAX];

// 1. 앞에서부터 차례로 비교
int seq_search1(int key, int low, int high){
	int i;
	
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;
			
	return -1; // 탐색 실패 
}
        
// 2. 배열 끝에 삽입한 뒤, 앞에서부터 찾기
int seq_search2(int key, int low, int high){
	int i;
	list[high+1] = key;
	for(i = low; list[i]!=key; i++);
	if (i == (high+1)) return -1; // 끝까지 오면 탐색 실패
	return i; 
}
        
// 3. 정렬된 배열에 대해
int sorted_seq_search3(int key, int low, int high){
	int i;
	for (i = low; i <= high; i++){
		if (list[i] > key) return -1; // 탐색 실패
		if (list[i] == key) return i; 
	}
}
