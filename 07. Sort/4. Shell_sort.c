// 셸 정렬
/*
	gap = (정렬 자료 개수) / 2
		- 단, gap이 짝수일 경우 +1(홀수화) 
	부분 리스트에 대해 삽입 정렬(두 번째부터 시작해서 앞과 비교) 
*/

const int n = 30;
int list[n];

void insertion_sort(int list[], int start, int n, int gap){
	int i, j, key;
	
	for (i = start+gap; i < n; i+=gap){
		key = list[i];
		for (j = i-gap; j >= start && list[j] > key; j-=gap)
			list[j+gap] = list[j];
		if ((j+gap) != i)
			list[j+gap] = key;
	}
}

void shell_sort(int list[], const int n){
	int i, gap;
	
	for (gap = n/2; gap > 0; gap /= 2){
		// gap이 짝수일 경우 +1(홀수화)
		if (gap % 2 == 0) gap++
		
		// 각 부분리스트에 대해 삽입 정렬(부분리스트 개수 == gap) 
		for (i = 0; i < gap; i++)
			insertion_sort(list, i, n, gap);
	}
} 
