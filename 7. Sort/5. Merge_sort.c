// 합병 정렬
int list[10];
int temp[10];

// 분할 & 합병 정렬 함수
void merge_sort(int list[], int temp[], int left, int right){ // left: 부분리스트 왼쪽 끝, right: 오른쪽 끝 
	// 1. 1개씩 남을 때까지 계속 절반으로 쪼개기
	int mid = (left + right) / 2;
	if (left < right){ // left == right면 1개까지 쪼개진 상태 
		merge_sort(list, temp, left, mid); // 쪼갠 왼쪽 부분
		merge_sort(list, temp, mid+1, right); // 쪼갠 오른쪽 부분
		
		// 2. 정렬하면서 합쳐서 올라오기 
		merge(list, temp, left, mid, right);
		
		// 3. 합치면 (부분)리스트 temp에 부분 정렬된 자료가 있으므로 원본 리스트에 복사
		for (int i = left; i <= right; i++)
			list[i] = temp[i];
	}
	return; // 1개까지 쪼개졌거나, 병합하면 종료(돌아감) 
} 

void merge(int list[], int temp[], int left, int mid, int right){
	// 파이프 방식으로 정렬하면서 merge 
	int i = left; // 왼쪽 부분리스트 시작점 
	int j = mid + 1; // 오른쪽 부분리스트 시작점
	int k = left; // 임시리스트에 저장하기 위한 인덱스 변수 
	int t; // 자료가 남아 있는 리스트를 비우기 위해 사용하는 변수 
	
	while (i <= mid && j <= right){
		if (list[i] < list[j]){ // 왼쪽 리스트 자료가 오른쪽 리스트 자료보다 작은 경우
			temp[k] = list[i]; // 임시 리스트에 왼쪽 자료 넣기
			i++;
			k++;
		}
		else{
			temp[k] = list[j];
			j++;
			k++;
		}
	}
	if (i > mid) // 왼쪽 리스트는 다 비었는데 오른쪽 리스트에는 자료 남은 경우
		for (t = j; t <= right; t++){
			temp[k] = list[t];
			k++;	
		}
	else{ // 오른쪽 리스트는 다 비었는데 왼쪽 리스트에는 자료 남은 경우
		for  (t = i; t <= mid; t++){
			temp[k] = list[t];
			k++;
		}
	}
}

// 합병함수 2(순환)
void iter_merge_sort(int list[], int n){
	// int temp[MAX_SIZE]; 
	int size = 1; // 부분리스트 크기 -> 2배씩 커져서 합병됨
	
	while (size < n){ // 1개로 다 합병될 때까지 
		mergePass(list, temp, n, size); // list -> temp에 정렬해서 담음
		size *= 2; // 부분 리스트 크기 2배씩
		mergePass(temp, list, n, size); // temp -> list에 정렬해서 담음
		size *= 2; 
	}	
} 

void mergePass(int list[], int temp[], int n, int size){
	int i, j;
	// 1. list[n] 배열에서 길이가 size인 인접한 한 쌍의 부분리스트를 합병하여 temp에 저장
	for (i = 0; i + 2*size <= n; i += 2*size)
		merge(list, temp, i, i+size-1, i+2*size-1); // merge(list[], temp[], left, mid, right) 
	
	// 2. 2*size보다 자료가 적게 남아 있는 부분 리스트 병합 
	if (i+size < n)
		merge(list, temp, i, i+size-1, n-1);
	
	// 3. 하나의 부분 리스트만 남았을 경우
	else
		for (j = i; j < n; j++)
			temp[j] = list[j];
}











