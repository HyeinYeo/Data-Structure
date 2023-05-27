// 선택 정렬 => 처음 시작, 가장 작은 수와 교환
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))
const int n = 30;
int list[n];

void selection_sort(int list[], const int n){
	int i, j, k, temp; // k는 가장 작은 자료 인덱스 담는 변수 
	
	for (i = 0; i < n-1; i++){
		k = i // 현재는 시작하는 자료가 가장 작다고 가정 
		for (j = i+1; j < n; j++)
			if (list[j] < list[k])
				k = j;
		if (k != i) // 시작한 자료가 가장 작은 경우가 아니면 
			SWAP(list[i], list[k], temp); // 교환 
	}
}

