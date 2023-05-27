// 삽입 정렬 => 두 번째부터 시작, 앞 자료들과 비교, 오른쪽으로 밀기
const int n = 30;
int list[n];

void insertion_sort(int list[], const int n){
	int i, j, key; 
	
	for (i = 1; i < n; i++){
		key = list[i];
		for (j = i-1; j >= 0 && list[j] > key; j--) // 앞 자료가 키보다 작아진 순간, 앞 자료 바로 다음 순서에 키 삽입 
			list[j+1] = list[j];

		if ((j+1)!= i)
			list[j+1] = key; 
	}
} 
