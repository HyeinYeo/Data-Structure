// 퀵 정렬
#define SWAP(x, y, z) ((temp)=(x), (x)=(y), (y)=(temp))

void quick_sort(int list[], int left, int right){
	if (left < right){ // left == right면 원소가 하나이므로 정렬, 비교할 필요 X 
		int pivot = partition(list, left, right);
		quick_sort(list, left, pivot-1); // 피벗 왼쪽 부분 리스트에 대해 다시 퀵 정렬
		quick_sort(list, pivot+1, right); // 피벗 오른쪽 부분 리스트에 대해 다시 퀵 정 
	}
	return; 
}

int partition(int list[], int left, int right){ // 피벗 인덱스 반환하는 함수
	int pivot_value = list[left]; // 가장 왼쪽값을 피벗으로 설정
	int start = left;
	int end = right + 1; // do-while 쓰기 위해 start, end 본격적 시작 위치 전에서 출발
	int temp;
	// start 포인터와 end 포인터가 겹치거나 교차하기 전까지 
	do{
		// start 포인터는 피벗보다 작은 값은 무시하고 오른쪽으로 계속 이동 
		do {start++;} while (list[start] < pivot_value && start <= right);
		
		// end 포인터는 피벗보다 큰 값은 무시하고 왼쪽으로 계속 이동
		do { end--; } while (list[end] > pivot_value && end >= left); 
		
		// start, end 포인터 모두 멈췄을 때, 두 값 교환
		if (start < end)
			SWAP(list[start], list[end], temp); 
	} while (start < end);
	
	// 교차한 때의 end 포인터 위치가 피벗 값의 위치
	SWAP(list[left], list[end], temp);
	
	// end 포인터 위치가 피벗의 인덱스이므로 리턴
	return end; 
}
